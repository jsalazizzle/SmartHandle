/***************************************************************************//**
* \file cy_bootload.h
* \version 2.20
*
* Provides API declarations for the Bootloader SDK.
*
********************************************************************************
* \copyright
* Copyright 2016-2018, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_BOOTLOAD_H)
#define CY_BOOTLOAD_H
    
/**
* \mainpage Cypress Bootloader SDK
*
* \section section_mainpage_overview Overview
*
* The purpose of the Bootloader SDK is to provide a low-level SDK for 
* bootloading firmware images. \n The Bootloader SDK has the following features:
* - Reading firmware images from the bootloading host through a number of 
*   transport interfaces, e.g. BLE, USB, UART, I2C, SPI, I2C.
* - Programming a firmware image to the specified address in internal Flash, 
*   SMIF, or any external memory that supports the Bootloader SDK API.
* - Copying applications.
* - Validating applications.
* - Safe Bootloading: bootloading images at temporary location, validating
*   them and if valid, overwrite working images.
* - Switching firmware applications.
*   Passing parameters in RAM when switching firmware applications.
* - Supports encrypted bootloader image files. \n
*   Transfers encrypted images to firmware without decrypting in the middle.
* - Supports up to 28 firmware images. Each of them can be a bootloader.
* - Supports customization.
* - CRC-32 checksum to validate firmware data.
* - Rejects firmware images for incompatible products by checking Product ID.
*   \n Rejects firmware images for incompatible chips by checking Silicon ID.
* - Designed to support Secure Library for PSoC6.
* - Can be easily ported to the PSoC4/5 and FMx Cypress device families.
* - Provides a number of code examples.
*
* The Bootloader SDK can be used for designing bootloading applications of 
* arbitrary flexibility and complexity. Also simple for simple cases.
*
* The simplest Bootloader SDK application is provided at the 
* CE213903 - Basic Bootloader code example.
*
* \section group_bootload_config Configuration Considerations
*
* \subsection group_bootload_config_linker_scripts Linker scripts
*
* The Bootloader SDK projects use linker scripts a bit different from the
* default startup linker scripts.
*
* Changes compared to startup linker scripts:
* 1. bootload_common.ld for GCC, bootload_common.icf for IAR,
*    bootload_common.h and bootload_mdk_symbols.c for MDK.
*
*    These files define the memory layout for each application inside the
*    device.
*
*    These files are Bootloader SDK specific, the startup linker scripts define
*    the memory layout by themselves. These common files are designed for better
*    user experience because the Bootloader SDK contains multiple applications.
*
* 2. bootload_cm0p.{ld, icf, scat}, bootload_cm4.{ld, icf, scat}
*    These files are the templates of linker script files for building
*    Bootloader SDK applications.
*    The user for GCC, IAR and MDK linkers to build CM0+ and CM4 applications.
*    Cypress Bootloader SDK code examples use them.
* 
* \par File bootload_common.ld
* This file is a GCC common linker script file. It is included into each
* application GCC linker script, and must have the same content across all
* the application projects inside the designed device.
*
* Any changes made to it in any application must be copied to other
* applications <i>bootload_common.ld</i> files.
*
* The goal of this design is to keep all the memory layout and common
* Bootloader SDK symbols in one file.
*
* Memory regions:
* This file defines all the memory regions for all the applications.
* Such a design allows the user to have a full memory layout inside one file.
* * <i>flash_app{X}_core{Y}</i> - The memory region for Flash code and data
*   of the user application {X} MCU core {Y}.
* * <i>flash_storage</i> - The optional memory region to place shared or 
*   application specific code or data outside of the application.
* * <i>flash_boot_meta</i> - The optional memory region for the Bootloader SDK
*   metadata. Cypress Bootloader SDK code examples place Bootloader SDK metadata 
*   inside this region. The user is free to place it in any other way.
* * <i>sflash_user_data</i>, <i>efuse</i>, <i>flash_toc</i>, <i>em_eeprom</i>,
*   <i>xip</i> - These are the regions not used by typical Bootloader
*   SDK code examples. They are kept because they may be used in user
*   code.
* * <i>ram_common</i> - The memory region for data that to be shared between
*   Bootloader SDK applications.
*   The user may place it anywhere inside the RAM, but all the applications must
*   have the same location of it.
*   So, one app sets some values there, switches to another app.
*   Then that another app may read or update the values.
* * <i>ram_app{X}_core{Y}</i> - The memory region for RAM data, stack, heap etc. 
*   for the user app{X} MCU core {Y}.
* 
* Common ELF file symbols:
* CyMCUElfTool uses special ELF file symbols besides command-line arguments for
* its configuration. Some of these symbols have values common for all the 
* applications and some are application-specific. Common symbols are defined in
* this file, while application-specific are in the linker scripts for that app.
* 1. __cy_memory_{N}_start - Defines the start address of the memory region.
*    __cy_memory_{N}_length - Defines the length of the memory region.
*    __cy_memory_{N}_row_size - Defines the row size of the memory region.
*
*    CyMCUElfTool uses these symbols to determine which memory regions should be
*    placed into the HEX and CYACD2 files. I.e. without these symbols, some data
*    like XIP may be absent in the HEX file.
*
*    These symbols are critical for CYACD2 file generation, CyMCUElfTool
*    must know the row size of all the data being exported to the CYACD2
*    file. The bootloading is done by rows, and a row size may vary across
*    the memory regions.
*
*    E.g. Internal Flash of PSoC6 devices start at address 0x1000_0000 and
*    the length and row size may de device-dependent, but let's assume it is
*    512KB and 512 bytes. The memory symbols for the internal Flash will be:
*    <code>
*        __cy_memory_0_start    = 0x10000000;
*        __cy_memory_0_length   = 512 * 1024;
*        __cy_memory_0_row_size = 512;
*    </code>
*
*    The number _{N}_ in the memory symbol indicates that there may be multiple
*    memories.
* 2. __cy_boot_metadata_addr and __cy_boot_metadata_length.
*    These symbols are used by the Bootloader SDK internally to access the 
*    metadata as the  metadata location is user-configurable.
* 3. __cy_product_id - used by CyMCUElfTool to be placed in the CYACD2 header.
*    This value is used by the Bootloading Host and Bootloader SDK firmware to
*    confirm that the CYACD2 file being bootloaded is compatible with
*    the device.
*
*    E.g. The user may have two different devices with the same PSoC6 chip:
*    * A coffee machine, with Product ID - 0x1000_0001.
*    * A nuclear power plant control device with Product ID - 0x1000_0002.
*    The user of a coffee machine tries to bootload firmware for a nuclear
*    power plant control device, and the Bootloader Host will indicate that
*    the device rejected this firmware because of the wrong Product ID.
* 4. __cy_app{N}_base, __cy_app{N}_size.
*    These symbols are used by the bootload_user.c file to initialize the 
*    metadata. Their value is automatically updated by the linker when the
*    user updates the memory layout (memory regions).
*
*    If the user decided to use a different mechanism for SDK metadata
*    initialization, then these symbols can be removed.
* 5. __cy_boot_signature_size.
*    Used by the Bootloader SDK linker scripts only. It helps avoiding the magic
*    number for a signature size to be scattered throughout all the linker 
*    scripts.
*    E.g.
*    * For the CRC-32C application signature, the value of this symbol is 4 
*      (bytes).
*    * For RSASSA-PCKS-1-v1.5 with RSA 2048, the value is 256 (bytes).
*
* \par File bootload_cm0p.ld
* This file is a linker script for the CM0+ core for Bootloader SDK 
* applications.
*
* It is similar to the default startup GCC's CM0+ linker script but with some
* differences:
* 1. include bootload_common.ld instead of defining memory regions.
* 2. __cy_app_id.
*    This ELF file symbols are used by CyMCUElfTool to set an application ID in 
*    the CYACD2 file header.
* 2. __cy_app_core1_start_addr.
*    This ELF file symbol is used for the CM0+ C code in the main_cm0p.c file 
*    to know the start address of the CM4 code.
*    Its value gets automatically updated when the memory layout gets changed.
*    The user should update the application number, when this linker script
*    is used for applications other than app 0.
* 3. __cy_app_verify_start, __cy_app_verify_length.
*    These two symbols are used by CyMCUElfTool to generate an application
*    signature. The first symbol provides a value of the start of signed memory 
*    and the second - the length of signed memory.
* 4. Section ".cy_boot_noinit".
*    Used to place data to be shared between the
*    applications. See the description of the ram_common memory region.
* 5. Section ".cy_boot_metadata".
*    Contains the Bootloader SDK metadata. This section name is necessary only 
*    for CyMCUElfTool to sign the section with the CRC-32C checksum 
*    of this section data.
*    If no CRC-32C at the end of the metadata is required, then the section can
*    be renamed.
* 6. No need to place __cy_memory_{N} symbols in this file, they are placed in
*    bootload_common.ld.
*
* \par File bootload_cm4.ld
* This file is a linker script for CM0+ core for the Bootloader SDK 
* applications.
*
* It is similar to a default startup GCC's CM0+ linker script and to a CM0+
* Bootloader SDK linker script but with some differences:
*
* Section .cy_app_signature.
* This section is used to place an application signature.
* The signature is used by the Bootloader SDK to verify that the application is
* valid.
*
* Typically, CRC, SHA or any other hash of the application code and data is
* placed here.
* CyMCUElfTool updates this section in the post-build step.
*
* The memory for which the signature is calculated is defined by the
* following ELF file symbols:
*    __cy_app_verify_start, __cy_app_verify_length.
*
* \par Files bootload_{cm0p, cm4}.{icf, scat}
* These files are the linker scripts for the CM0+ and CM4 cores for IAR and MDK
* compilers for the Bootloader SDK applications.
*
* Their difference from the default startup linker scripts are similar to
* the Bootloader SDK GCC's linker scripts described above.
*
*
* \section group_bootload_more_info More Information
*
* * [AN213924](http://www.cypress.com/an213924) Bootloader SDK User Guide
* * [CE213903](http://www.cypress.com/ce213903)
*   Bootloader SDK Basic Communication Code Examples
* * [CE216767](http://www.cypress.com/ce216767)
*   Bootloader SDK BLE OTA Code Example
*
* \section group_bootload_MISRA MISRA-C Compliance 
* <table class="doxtable">
*   <tr>
*     <th>MISRA Rule</th>
*     <th>Rule Class (Required/Advisory)</th>
*     <th>Rule Description</th>
*     <th>Description of Deviation(s)</th>
*   </tr>
*   <tr>
*     <td>1.1</td>
*     <td>R</td>
*     <td>This rule states that code shall conform to C ISO/IEC 9899:1990
*         standard.</td>
*     <td>PDL v3.0.1 supports the ISO:C99 standard.</td>
*   </tr>
*   <tr>
*     <td>2.3</td>
*     <td>A</td>
*     <td>Nested comments are not recognized in the ISO standard.</td>
*     <td>
*         The comments provide the useful WEB link to the additional 
*         documentation.
*     </td>
*   </tr>
*   <tr>
*     <td>3.1</td>
*     <td>R</td>
*     <td>All usage of implementation defined behavior shall be documented</td>
*     <td>The Bootloader SDK deviates rule 11.3 which triggers rule 3.1.
*         The ANSI symbols Dollar and Back quote are used by PDL v.3.0.1
*         headers before being preprocessed.</td>
*   </tr>
*   <tr>
*     <td>5.6</td>
*     <td>A</td>
*     <td>To avoid confusion, no identifier in one name space should have the
*         same spelling as an identifier in another name space, with the
*         exception of structure and union member names</td>
*     <td>This rule is deviated because the generalized implementation approach
*         requires having the same names.</td>
*   </tr>
*   <tr>
*     <td>8.7</td>
*     <td>R</td>
*     <td>Objects shall be defined at block scope if they are only accessed from
*         within a single function. That is, minimize the scope of objects and
*         variables</td>
*     <td>For some communication APIs, an object scope can be reduced, but that
*          is not because of the generalized implementation approach.</td>
*   </tr>
*   <tr>
*     <td>9.2</td>
*     <td>R</td>
*     <td>Braces shall be used to indicate and match the structure in the
*         nonzero initialization of arrays and structures</td>
*     <td>This rule is deviated in the bootload_user.c file,
*         it is manually checked to be valid.</td>
*   </tr>
*   <tr>
*     <td>11.3</td>
*     <td>A</td>
*     <td>Avoid casts between a pointer type and an integral type</td>
*     <td>There are a few casts between the pointer and uint32_t type in
*         the cy_bootload.c file. All of them are manually verified and reviewed
*         to be safe.</td>
*   </tr>
*   <tr>
*     <td>11.4</td>
*     <td>A</td>
*     <td>A cast should not be performed between a pointer to object type and
*         a different pointer to object type.</td>
*     <td>Casts involving pointers are conducted with caution that the pointers
*         are correctly aligned for the type of the object being pointed to.
*     </td>
*   </tr>
*   <tr>
*     <td>11.5</td>
*     <td>R</td>
*     <td>Not performed, the cast that removes any const or volatile 
*           qualification from the type addressed by a pointer.</td>
*     <td>The removal of the volatile qualification inside the function has no 
*           side effects.</td>
*   </tr>
*   <tr>
*     <td>13.7</td>
*     <td>R</td>
*     <td>Boolean operations whose results are invariant shall not be
*         permitted.</td>
*     <td>MISRA-C:2004 is not smart enough to understand the function is weak,
*         thus may return values other than in the default implementation.</td>
*   </tr>
*   <tr>
*     <td>14.1</td>
*     <td>R</td>
*     <td>There shall be no unreachable code. This refers to code which cannot,
*         under any circumstances, be reached.</td>
*     <td>MISRA-C:2004 does not understand that a weak function is supposed to 
*         be overwritten in the customer project. Thus assumes the function 
*         returns always the same fixed value, so any if() branch testing 
*         weak-function return-value may be treated as unreachable code.</td>
*   </tr>
*   <tr>
*     <td>14.2</td>
*     <td>R</td>
*     <td>All non-null statements shall either have at least one side-effect,
*         however executed, or cause control flow to change.</td>
*     <td>MISRA-C:2004 is not smart enough to understand the intention of
*         the (void)unused_param; statement. \n
*         GCC, MDK and IAR compilers understand the intention of this.</td>
*   </tr>
*   <tr>
*     <td>16.7</td>
*     <td>A</td>
*     <td>The object addressed by the pointer parameter is not modified
*         and so the pointer could be of type 'pointer to const'.</td>
*     <td>Some Bootloader SDK functions are weak, and can be redefined in
*         the user code. They contain non-const pointer parameters intentionally
*         to be more generic .</td>
*   </tr>
*   <tr>
*     <td>17.4</td>
*     <td>R</td>
*     <td>Array indexing shall be the only allowed form of pointer arithmetic
*         </td>
*     <td>There are several instances of the pointer arithmetic in 
*         cy_bootload.c. They cannot be avoided, so are manually checked 
*         and reviewed to be safe.</td>
*   </tr>
*   <tr>
*     <td>19.7</td>
*     <td>A</td>
*     <td>A function shall be used in preference to a function-like macro</td>
*     <td>Function-like macros are used for performance reasons.</td>
*   </tr>
*   <tr>
*     <td>19.13</td>
*     <td>A</td>
*     <td>Avoid use of the # and ## preprocessor directives when possible</td>
*     <td>The directive ## of the preprocessor used in the  
*         transport_uart/i2c/spi.c. The use of ## is intentional and allows 
*         setting the UART/I2C/SPI component name in one place and does not 
*         change it throughout the whole transport_uart/i2c/spi.c file.</td>
*   </tr>
*   <tr>
*     <td>21.1</td>
*     <td>R</td>
*     <td>Minimization of run-time failures shall be ensured by the use of
*         at least one of:
*         * static analysis tools/techniques;
*         * dynamic analysis tools/techniques;
*         * explicit coding of checks to handle run-time faults.</td>
*     <td>Redundant operations are present because of the generalized
*         implementation approach.</td>
*   </tr>
* </table>
*
* \section group_bootload_changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td rowspan="2">2.20</td>
*     <td> Add check of application number in Set Application Metadata command 
*          processing routine. 
*     </td>
*     <td>
*           Prevent incorrect usage of the Set Application Metadata command.
*     </td>
*   </tr>
*   <tr>
*     <td>Minor documentation updates</td>
*     <td>Documentation improvement</td>
*   </tr>
*   <tr>
*     <td>2.10</td>
*     <td> Moved address and golden image checks from cy_bootload.c to 
*       \ref Cy_Bootload_WriteData() in bootload_user.c, so the checks can be 
*       customized based on application needs.
*     </td>
*     <td>Allows receiving an update for the running app use case.
*         Improvements made based on usability feedback. 
*         Documentation update and clarification.
*     </td>
*   </tr>
*   <tr>
*     <td>2.0</td>
*     <td>
*       <ul>
*         <li>Use the shared RAM for application switching
*             instead of the BACKUP register.</li>
*         <li>Add support of secure application verification.</li>
*         <li>Add support of I2C/SPI/BLE transport protocols.</li>
*         <li>Linker scripts updated for PSoC6 Rev *A devices.</li>
*         <li>Made CRC default application checksum.</li>
*       </ul>
*     </td>
*     <td>To increase functionality.</td>
*   </tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version.</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_bootload_macro         Macros
* \{
* \defgroup group_bootload_macro_config  User Config Macros
* \}
* \defgroup group_bootload_functions     Functions
* \defgroup group_bootload_globals       Global Variables
* \defgroup group_bootload_data_structs  Data Structures
* \defgroup group_bootload_enums         Enumerated Types
*/

#if !defined(__GNUC__) && !defined(__ARMCC_VERSION) && !defined(__ICCARM__)
    #error "Unsupported compiler, use either GNU, MDK or IAR C compilers"
#endif

#include <stdint.h>
#include "bootload_user.h"

#if CY_BOOTLOAD_OPT_CRYPTO_HW != 0
    #include "crypto/cy_crypto.h"
#endif

#include "syslib/cy_syslib.h"


#ifdef __cplusplus
extern "C"{
#endif

/**
* \addtogroup group_bootload_macro
* \{
*/

/** The Bootloader SDK major version */
#define CY_BOOTLOADER_SDK_VERSION_MAJOR       2 
/** The Bootloader SDK minor version */
#define CY_BOOTLOADER_SDK_VERSION_MINOR       20   

/**
* \defgroup group_bootload_macro_state Bootload State
* \{
* The state of bootloading. \n
* This is a set of values that the bootloader state variable can hold. \n
* When Cy_Bootload_Continue() and Cy_Bootload_DoBootload() return, the state parameter
* indicates whether the bootloader has finished successfully or what is the unsuccessful
* state.
*/
#define CY_BOOTLOAD_STATE_NONE          (0u) /**< Bootloading has not yet started, no Enter packet received */
#define CY_BOOTLOAD_STATE_BOOTLOADING   (1u) /**< Bootloading is in process             */
#define CY_BOOTLOAD_STATE_FINISHED      (2u) /**< Bootloading has finished successfully */
#define CY_BOOTLOAD_STATE_FAILED        (3u) /**< Bootloading has finished with error   */
/** \} group_bootload_macro_state */

#define CY_BOOTLOAD_PACKET_MIN_SIZE     (0x07u) /**< Smallest valid bootloader packet size */

/**
* \defgroup group_bootload_macro_commands Bootloader Commands
* \{
*/
#define CY_BOOTLOAD_CMD_ENTER           (0x38u) /**< Bootloader command: Enter Bootloader           */
#define CY_BOOTLOAD_CMD_EXIT            (0x3Bu) /**< Bootloader command: Exit Bootloader            */
#define CY_BOOTLOAD_CMD_PROGRAM_DATA    (0x49u) /**< Bootloader command: Program Data               */
#define CY_BOOTLOAD_CMD_VERIFY_DATA     (0x4Au) /**< Bootloader command: Verify Data                */
#define CY_BOOTLOAD_CMD_ERASE_DATA      (0x44u) /**< Bootloader command: Erase Data                 */
#define CY_BOOTLOAD_CMD_VERIFY_APP      (0x31u) /**< Bootloader command: Verify Application         */
#define CY_BOOTLOAD_CMD_SEND_DATA       (0x37u) /**< Bootloader command: Send Data                  */
#define CY_BOOTLOAD_CMD_SEND_DATA_WR    (0x47u) /**< Bootloader command: Send Data without Response */
#define CY_BOOTLOAD_CMD_SYNC            (0x35u) /**< Bootloader command: Sync Bootloader            */
#define CY_BOOTLOAD_CMD_SET_APP_META    (0x4Cu) /**< Bootloader command: Set Application Metadata   */
#define CY_BOOTLOAD_CMD_GET_METADATA    (0x3Cu) /**< Bootloader command: Get Metadata               */
#define CY_BOOTLOAD_CMD_SET_EIVECTOR    (0x4Du) /**< Bootloader command: Set EI Vector              */

/** \} group_bootload_macro_commands */

/**
* \defgroup group_bootload_macro_ioctl Read/Write Data IO Control Values
* \{
* The values of the ctl parameter to \ref Cy_Bootload_ReadData() and \ref Cy_Bootload_WriteData() functions.
* - Bit 0:
*   * 0, Normal read or write operations.
*   * 1, Erase a memory page for write operations.
*        Compare a memory page with the data in the buffer for read operation.
* - Bit 1:
*   * 0, Read or write with raw data
*   * 1, Data received from/to be sent to the Bootloader Host.
*        May require encryption/decryption or any other special treatment.
         E.g. read/write a data from/to an address with an offset.
* - Bit 2: Reserved.
* - Bit 3: Reserved.
* - Bit 4 - 31: Unused in Bootloader SDK. Up to the user to specify it.
*/

#define CY_BOOTLOAD_IOCTL_READ          (0x00u) /**< Read data into buffer                         */
#define CY_BOOTLOAD_IOCTL_COMPARE       (0x01u) /**< Compare read data with the data in the buffer */

#define CY_BOOTLOAD_IOCTL_WRITE         (0x00u) /**< Write buffer to communication */
#define CY_BOOTLOAD_IOCTL_ERASE         (0x01u) /**< Erase memory page             */

#define CY_BOOTLOAD_IOCTL_BHP           (0x02u) /**< Data from/to Bootloader Host. It may require decryption */

/** \} group_bootload_macro_ioctl */

/**
* \defgroup group_bootload_macro_response_size Response Size
* \{
*/

#define CY_BOOTLOAD_RSP_SIZE_0          (0u)    /**< Data size for most bootloader commands responses */
#define CY_BOOTLOAD_RSP_SIZE_VERIFY_APP (1u)    /**< Data size for 'Verify Application' bootloader command response */

/** \} group_bootload_macro_response_size */

/** Bootloader SDK PDL ID */
#define CY_BOOTLOAD_ID                  CY_PDL_DRV_ID(0x06u)


/**
* \defgroup group_bootload_macro_app_type Application types
* \{
* Used to define what application format is expected.
*/
#define CY_BOOTLOAD_BASIC_APP           (0u)    /**< Application format for non-secure applications */
#define CY_BOOTLOAD_CYPRESS_APP         (1u)    /**< Cypress Standard User Application format */
#define CY_BOOTLOAD_SIMPLIFIED_APP      (2u)    /**< Simplified User Application Object format */
/** \} group_bootload_macro_app_type */

/**
* \defgroup group_bootload_macro_ver_type Types of secure application verification
* \{
* Used to define what type of secure application verification is expected.
*/
#define CY_BOOTLOAD_VERIFY_FAST         (0u)    /**< Verification includes only application check*/
#define CY_BOOTLOAD_VERIFY_FULL         (1u)    /**< Verification includes application, key, and TOC checks */
/** \} group_bootload_macro_ver_type */

/** \} group_bootload_macro */

/**
* \addtogroup group_bootload_data_structs
* \{
*/

/** Working parameters for some Bootloader SDK APIs. */
typedef struct
{
    /**
    * The pointer to a buffer that keeps data to read or write to an NVM.
    * It is required to be 4-byte aligned.
    */
    uint8_t  *dataBuffer;
    uint32_t  dataOffset;   /**< Offset within \c dataBuffer to put next chunk of data */
    /**
    * The pointer to a buffer that keeps packets sent and received with the Transport API.
    * It is required to be 4-byte aligned.
    */
    uint8_t  *packetBuffer;
    uint32_t  timeout;      /**< The timeout value in milliseconds */
    uint32_t  appId;        /**< Set with the Set App Metadata bootloader command.
                            *    Used to determine an appId of bootloaded image  */
    uint32_t  appVerified;  /**< Internal, flags if Verify Application is called before Exit */
    
    /**
    * The initial value to the ctl parameter for
    * \ref Cy_Bootload_ReadData and \ref Cy_Bootload_WriteData.
    * The Bootloader SDK functions call Read/Write Data functions like this: \n
    * Cy_Bootload_ReadData(addr, length, CY_BOOTLOAD_IOCTL_COMPARE, params).
    */
    uint32_t  initCtl;
    
#if CY_BOOTLOAD_OPT_SET_EIVECTOR != 0
    /**
    * The pointer to an Encryption Initialization Vector buffer.
    * Must be 0-, 8-, or 16-byte long and 4-byte aligned.
    * This may be used in \ref Cy_Bootload_ReadData and \ref Cy_Bootload_WriteData
    * to encrypt or decrypt data when the CY_BOOTLOAD_IOCTL_BHP flag is set in the
    * ctl parameter.
    */
    uint8_t *encryptionVector;
#endif /* CY_BOOTLOAD_OPT_SET_EIVECTOR != 0 */
    
} cy_stc_bootload_params_t;

/**
* Only used inside BootloaderCommand_Enter().
* \note A public definition because the user may want to redefine 
* the bootloader packet.
*/
typedef struct
{
    uint32_t enterSiliconId;             /**< The silicon ID for a device */
    uint8_t  enterRevision;              /**< Silicon Revision for a device */
    uint8_t  enterBootloaderVersion[3];  /**< The Bootloader SDK version */
} cy_stc_bootload_enter_t;
/** \} group_bootload_data_structs */

/**
* \addtogroup group_bootload_enums
* \{
*/

/** Used to return the statuses of most Bootloader SDK APIs */
typedef enum
{
    /** Correct status, No error */
    CY_BOOTLOAD_SUCCESS         =                                        0x00u,
    /** Verification failed */
    CY_BOOTLOAD_ERROR_VERIFY    = CY_BOOTLOAD_ID | CY_PDL_STATUS_ERROR | 0x02u,
    /** The length of received packet is outside of expected range */
    CY_BOOTLOAD_ERROR_LENGTH    = CY_BOOTLOAD_ID | CY_PDL_STATUS_ERROR | 0x03u,
    /** The data in the received packet is invalid */
    CY_BOOTLOAD_ERROR_DATA      = CY_BOOTLOAD_ID | CY_PDL_STATUS_ERROR | 0x04u,
    /** Command is not recognized */
    CY_BOOTLOAD_ERROR_CMD       = CY_BOOTLOAD_ID | CY_PDL_STATUS_ERROR | 0x05u,
    /** checksum does not match the expected value */
    CY_BOOTLOAD_ERROR_CHECKSUM  = CY_BOOTLOAD_ID | CY_PDL_STATUS_ERROR | 0x08u,
    /** Wrong address */
    CY_BOOTLOAD_ERROR_ADDRESS   = CY_BOOTLOAD_ID | CY_PDL_STATUS_ERROR | 0x0Au,
    /** Command timed out */
    CY_BOOTLOAD_ERROR_TIMEOUT   = CY_BOOTLOAD_ID | CY_PDL_STATUS_ERROR | 0x40u,
    /** Unknown bootloader error, this shall not happen */
    CY_BOOTLOAD_ERROR_UNKNOWN   = CY_BOOTLOAD_ID | CY_PDL_STATUS_ERROR | 0x0Fu
} cy_en_bootload_status_t;


/** \} group_bootload_enums */

/**
* \addtogroup group_bootload_globals
* \{
*/

/**
* \defgroup group_bootload_globals_external_elf_symbols External ELF file symbols
* \{
* These symbols are added to the generated ELF file. \n
* Their values are either defined in the linker script (GCC, IAR)
* or in an assembly code (MDK).
* They may be used by CyMCUElfTool as parameters for generating a CYACD2 file.
* Also, the Bootloader SDK APIs may user them to refer link-time known values
* to the compile time.
*/
extern uint8_t __cy_boot_metadata_addr;     /**< Metadata address           */
extern uint8_t __cy_boot_metadata_length;   /**< Metadata row size          */
extern uint8_t __cy_product_id;             /**< Product ID                 */
extern uint8_t __cy_checksum_type;          /**< Checksum Algorithm for BHP */
extern uint8_t __cy_app_id;                 /**< Current application number */
extern uint8_t __cy_app_core1_start_addr;   /**< core1 vector table address, if present */
/** \} group_bootload_globals_external_elf_symbols */

/** \} group_bootload_globals */

/**
* \addtogroup group_bootload_functions
* \{
*/

cy_en_bootload_status_t Cy_Bootload_DoBootload(uint32_t *state, uint32_t timeout);
cy_en_bootload_status_t Cy_Bootload_Init(uint32_t *state, cy_stc_bootload_params_t *params);
cy_en_bootload_status_t Cy_Bootload_Continue(uint32_t *state, cy_stc_bootload_params_t *params);

void Cy_Bootload_ExecuteApp(uint32_t appId);
cy_en_bootload_status_t Cy_Bootload_SwitchToApp(uint32_t appId);

uint32_t Cy_Bootload_DataChecksum(const uint8_t *address, uint32_t length, cy_stc_bootload_params_t *params);
cy_en_bootload_status_t Cy_Bootload_ValidateMetadata(uint32_t metadataAddress, cy_stc_bootload_params_t *params);
cy_en_bootload_status_t Cy_Bootload_ValidateApp(uint32_t appId, cy_stc_bootload_params_t *params);

uint32_t Cy_Bootload_GetRunningApp(void);

cy_en_bootload_status_t Cy_Bootload_GetAppMetadata(uint32_t appId, uint32_t *verifyAddress, uint32_t *verifySize);

#if CY_BOOTLOAD_METADATA_WRITABLE != 0
    cy_en_bootload_status_t Cy_Bootload_SetAppMetadata(uint32_t appId, uint32_t verifyAddress,
                                                       uint32_t verifySize, cy_stc_bootload_params_t *params);
#endif /* if CY_BOOTLOAD_METADATA_WRITABLE != 0 */

cy_en_bootload_status_t Cy_Bootload_CopyApp(uint32_t destAddress, uint32_t srcAddress, uint32_t length,
                                            uint32_t rowSize, cy_stc_bootload_params_t *params);

void Cy_Bootload_OnResetApp0(void);

/* These 2 IO functions have to be re-implemented in the user's code */
cy_en_bootload_status_t Cy_Bootload_ReadData (uint32_t address, uint32_t length, uint32_t ctl, 
                                              cy_stc_bootload_params_t *params);
cy_en_bootload_status_t Cy_Bootload_WriteData(uint32_t address, uint32_t length, uint32_t ctl, 
                                              cy_stc_bootload_params_t *params);

/* These 5 communication functions have to be re-implemented in the user's code */
cy_en_bootload_status_t Cy_Bootload_TransportRead (uint8_t buffer[], uint32_t size, uint32_t *count, uint32_t timeout);
cy_en_bootload_status_t Cy_Bootload_TransportWrite(uint8_t buffer[], uint32_t size, uint32_t *count, uint32_t timeout);
void Cy_Bootload_TransportReset(void);
void Cy_Bootload_TransportStart(void);
void Cy_Bootload_TransportStop(void);


/** \} group_bootload_functions */

#ifdef __cplusplus
}
#endif

#endif /* !defined(CY_BOOTLOAD_H) */


/* [] END OF FILE */
