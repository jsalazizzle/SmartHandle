// ======================================================================
// Bike FSM_new.v generated from TopDesign.cysch
// 01/20/2019 at 00:14
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_FAMILY_PSOC6 4
`define CYDEV_CHIP_FAMILY_FM0P 5
`define CYDEV_CHIP_FAMILY_FM3 6
`define CYDEV_CHIP_FAMILY_FM4 7
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_MEMBER_5B 2
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_MEMBER_5A 3
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_MEMBER_4G 4
`define CYDEV_CHIP_REVISION_4G_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4G_ES 17
`define CYDEV_CHIP_REVISION_4G_ES2 33
`define CYDEV_CHIP_MEMBER_4U 5
`define CYDEV_CHIP_REVISION_4U_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4E 6
`define CYDEV_CHIP_REVISION_4E_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0
`define CYDEV_CHIP_MEMBER_4O 7
`define CYDEV_CHIP_REVISION_4O_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4R 8
`define CYDEV_CHIP_REVISION_4R_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4T 9
`define CYDEV_CHIP_REVISION_4T_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4N 10
`define CYDEV_CHIP_REVISION_4N_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4S 11
`define CYDEV_CHIP_REVISION_4S_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Q 12
`define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4D 13
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4J 14
`define CYDEV_CHIP_REVISION_4J_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4K 15
`define CYDEV_CHIP_REVISION_4K_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4V 16
`define CYDEV_CHIP_REVISION_4V_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 17
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 18
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 19
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4P 20
`define CYDEV_CHIP_REVISION_4P_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4M 21
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 22
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4I 23
`define CYDEV_CHIP_REVISION_4I_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_6A 24
`define CYDEV_CHIP_REVISION_6A_ES 17
`define CYDEV_CHIP_REVISION_6A_PRODUCTION 33
`define CYDEV_CHIP_REVISION_6A_NO_UDB 33
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 25
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 26
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 27
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM3 28
`define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM4 29
`define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_USED 4
`define CYDEV_CHIP_MEMBER_USED 24
`define CYDEV_CHIP_REVISION_USED 33
// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// Component: or_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\or_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\or_v1_0\or_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\or_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\or_v1_0\or_v1_0.v"
`endif

// SCB_UART_PDL_v2_0(BaudRate=115200, BitsOrder=0, BreakSignalBits=11, BufferMinSize=64, ByteMode=true, ClkFreqDes=1382.4, ClkMinusTolerance=5, ClkPlusTolerance=5, ClockFromTerm=false, ComMode=0, CtsPolarity=0, CtsTermEnable=false, DataWidth=8, Direction=3, DropOnFrameErr=false, DropOnParityErr=false, EnableCts=false, EnableInputFilter=false, EnableMultiProc=false, EnableRts=false, EnableRxOutput=false, EnableTxEn=false, EnableTxOutput=false, InterruptMode=1, InterruptTermEnable=false, IntrRxBreakDetected=false, IntrRxFrameErr=false, IntrRxFull=false, IntrRxNotEmpty=false, IntrRxOverflow=false, IntrRxParityErr=false, IntrRxTrigger=false, IntrRxUnderflow=false, IntrTxEmpty=false, IntrTxNotFull=false, IntrTxOverflow=false, IntrTxTrigger=false, IntrTxUartDone=false, IntrTxUartLostArb=false, IntrTxUartNack=false, IntrTxUnderflow=false, IrdaLowPower=false, IrdaPolarity=0, IsCtsPinAllowed=true, IsDmaCapable=true, IsEnableInputFilterVisible=true, IsMultiprocessorModeAvailable=false, IsRtsPinAllowed=true, IsRtsTriggerLevelVisible=false, IsRxIntrSourcesVisible=false, IsRxTriggerLevelVisible=false, IsTxIntrSourcesVisible=false, IsTxTriggerLevelVisible=false, MaxFifoLevel=127, MpRxAcceptAddress=false, MpRxAddress=0, MpRxAddressMask=255, OvsFactor=12, ParityType=0, PreconfigureIO=false, RemoveCtsPin=true, RemoveIntr=false, RemoveRtsPin=true, RemoveRxPin=false, RemoveRxTxPin=true, RemoveTxEnPin=true, RemoveTxPin=false, RtsPolarity=0, RtsTermEnable=false, RtsTriggerLevel=4, RxIntrMask=0, RxTermEnable=false, RxTriggerLevel=7, RxTxTermEnable=false, ShowTerminals=false, SmCardRetryOnNack=false, StopBits=2, SymbolShape=0, TriggerOutputEnable=false, TxEnTermEnable=false, TxIntrMask=0, TxTermEnable=false, TxTriggerLevel=0, UartMode=2, UseIntr=true, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=SCB_UART_PDL_v2_0, CY_CONFIG_TITLE=UART_DEBUG, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=UART_DEBUG, CY_INSTANCE_SHORT_NAME=UART_DEBUG, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=scb, CY_PDL_DRIVER_REQ_VERSION=2.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=UART_DEBUG, )
module SCB_UART_PDL_v2_0_0 (
    cts_in,
    tx_out,
    rts_out,
    interrupt,
    clock,
    rx_dma,
    tx_dma,
    rx_in,
    rx_tx_out,
    tx_en_out);
    input       cts_in;
    output      tx_out;
    output      rts_out;
    output      interrupt;
    input       clock;
    output      rx_dma;
    output      tx_dma;
    input       rx_in;
    output      rx_tx_out;
    output      tx_en_out;


          wire  rx_wire;
          wire  tx_wire;
          wire  rts_wire;
          wire  cts_wire;
          wire  intr_wire;
          wire  clock_wire;
          wire  Net_161;
          wire  Net_157;
          wire  Net_156;
          wire [3:0] Net_155;
          wire  Net_154;
          wire  Net_150;
          wire  Net_149;
          wire  Net_148;
          wire  Net_147;
          wire  Net_146;
          wire  Net_145;
          wire  Net_1172;
          wire  Net_23;
          wire  tx_en_wire;
          wire  Net_47;
          wire  Net_22;
          wire  Net_24;
          wire  Net_847;


	cy_clock_v1_0
		#(.id("457aa532-fb8a-43be-a91c-7c89e876418d/b68e5b9d-7828-482d-a282-930f990e3b3e"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("723379629.62963"),
		  .is_direct(0),
		  .is_digital(0))
		SCBCLK
		 (.clock_out(Net_847));


	// clock_VM (cy_virtualmux_v1_0)
	assign clock_wire = Net_847;

    ZeroTerminal ZeroTerminal_7 (
        .z(Net_22));


    assign Net_23 = Net_22 | Net_847;

	wire [0:0] tmpFB_0__tx_net;
	wire [0:0] tmpIO_0__tx_net;
	electrical [0:0] tmpSIOVREF__tx_net;

	cy_mxs40_gpio_v1_0
		#(.id("457aa532-fb8a-43be-a91c-7c89e876418d/65f3af6c-759b-4ccb-8c66-5c95ba1f5f4f"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("1"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		tx
		 (.oe({1'b1}),
		  .y({tx_wire}),
		  .fb({tmpFB_0__tx_net[0:0]}),
		  .io({tmpIO_0__tx_net[0:0]}),
		  .siovref(tmpSIOVREF__tx_net));


	wire [0:0] tmpIO_0__rx_net;
	electrical [0:0] tmpSIOVREF__rx_net;

	cy_mxs40_gpio_v1_0
		#(.id("457aa532-fb8a-43be-a91c-7c89e876418d/b7e8018e-1ef7-49c0-b5a5-61641a03e31c"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("0"),
		  .ibuf_enabled("1"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		rx
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({Net_1172}),
		  .io({tmpIO_0__rx_net[0:0]}),
		  .siovref(tmpSIOVREF__rx_net));


	// rx_VM (cy_virtualmux_v1_0)
	assign rx_wire = Net_1172;

	// cts_VM (cy_virtualmux_v1_0)
	assign cts_wire = cts_in;


	cy_mxs40_isr_v1_0
		#(.deepsleep_required(0),
		  .int_type(2'b10))
		SCB_IRQ
		 (.int_signal(intr_wire));


    cy_mxs40_scb_v1_10 SCB (
        .clock(clock_wire),
        .uart_rx(rx_wire),
        .uart_cts(cts_wire),
        .i2c_scl(Net_145),
        .i2c_sda(Net_146),
        .spi_clk_s(1'b0),
        .spi_select_s(1'b0),
        .spi_miso_m(1'b0),
        .spi_mosi_s(1'b0),
        .uart_tx(tx_wire),
        .uart_rts(rts_wire),
        .uart_tx_en(tx_en_wire),
        .spi_clk_m(Net_154),
        .spi_select_m(Net_155[3:0]),
        .spi_mosi_m(Net_156),
        .spi_miso_s(Net_157),
        .interrupt(intr_wire),
        .tr_tx_req(tx_dma),
        .tr_rx_req(rx_dma),
        .tr_i2c_scl_filtered(Net_161));
    defparam SCB.master = 0;
    defparam SCB.mode = 2;
    defparam SCB.requires_io_preconfigure = 0;


    assign tx_out = tx_wire;

    assign rts_out = rts_wire;

    assign interrupt = intr_wire;

    assign rx_tx_out = tx_wire;

    assign tx_en_out = tx_en_wire;


endmodule

// MCWDT_PDL_v1_10(C0_enable=false, C0ClearOnMatch=1, C0Match=32768, C0Mode=0, C1_enable=false, C1ClearOnMatch=0, C1Match=32768, C1Mode=1, C2_enable=false, C2Mode=0, C2Period=16, CascadeC0C1=true, CascadeC1C2=false, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=MCWDT_PDL_v1_10, CY_CONFIG_TITLE=MCWDT, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=MCWDT, CY_INSTANCE_SHORT_NAME=MCWDT, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=10, CY_PDL_DRIVER_NAME=mcwdt, CY_PDL_DRIVER_REQ_VERSION=1.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=MCWDT, )
module MCWDT_PDL_v1_10_1 (
    interrupt);
    output      interrupt;



    cy_mxs40_mcwdt_v1_0 MCWDT (
        .interrupt(interrupt));



endmodule

// SCB_I2C_PDL_v2_0(AcceptAddress=false, AcceptGeneralCall=false, ClkDesFrequency=7820, ClkMinusTolerance=5, ClkPlusTolerance=127.877237851662, ClockFromTerm=false, DataRate=400, DeepSleepCapable=false, EnableManualSclControl=false, EnableRxFifo=false, EnableSclAccess=false, EnableTxFifo=false, EnableWakeup=false, HighPhaseDutyCycle=10, I2cMode=0, IsEnableRxFifoVisible=true, IsMasterEnabled=true, IsSlaveVisible=false, LowPhaseDutyCycle=10, Mode=2, ShowTerminals=false, SlaveAddress=8, SlaveAddressMask=254, SymbolShape=0, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=SCB_I2C_PDL_v2_0, CY_CONFIG_TITLE=SensorBus, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=SensorBus, CY_INSTANCE_SHORT_NAME=SensorBus, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=scb, CY_PDL_DRIVER_REQ_VERSION=2.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=SensorBus, )
module SCB_I2C_PDL_v2_0_2 (
    clock,
    scl_b,
    sda_b,
    scl_trig);
    input       clock;
    inout       scl_b;
    inout       sda_b;
    output      scl_trig;


          wire  clock_wire;
          wire  Net_222;
          wire  Net_224;
          wire  Net_223;
          wire  Net_163;
          wire  Net_162;
          wire  Net_1055;
          wire  Net_1061;
          wire [3:0] Net_87;
          wire  Net_1059;
          wire  intr_wire;
          wire  Net_277;
          wire  Net_1053;
          wire  Net_1062;
          wire  Net_278;
          wire  Net_279;
          wire  Net_280;
          wire  Net_281;
          wire  Net_282;
          wire  Net_283;
          wire  Net_847;

    cy_mxs40_scb_v1_10 SCB (
        .clock(clock_wire),
        .uart_rx(Net_283),
        .uart_cts(Net_282),
        .i2c_scl(scl_b),
        .i2c_sda(sda_b),
        .spi_clk_s(Net_281),
        .spi_select_s(Net_280),
        .spi_miso_m(Net_279),
        .spi_mosi_s(Net_278),
        .uart_tx(Net_1062),
        .uart_rts(Net_1053),
        .uart_tx_en(Net_277),
        .spi_clk_m(Net_1059),
        .spi_select_m(Net_87[3:0]),
        .spi_mosi_m(Net_1061),
        .spi_miso_s(Net_1055),
        .interrupt(intr_wire),
        .tr_tx_req(Net_162),
        .tr_rx_req(Net_163),
        .tr_i2c_scl_filtered(scl_trig));
    defparam SCB.master = 1;
    defparam SCB.mode = 0;
    defparam SCB.requires_io_preconfigure = 1;


    assign Net_224 = Net_223 | Net_847;

    ZeroTerminal ZeroTerminal_7 (
        .z(Net_223));

	// clock_VM (cy_virtualmux_v1_0)
	assign clock_wire = Net_847;

    ZeroTerminal ZeroTerminal_6 (
        .z(Net_278));

    ZeroTerminal ZeroTerminal_5 (
        .z(Net_279));

    ZeroTerminal ZeroTerminal_4 (
        .z(Net_280));

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_281));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_282));

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_283));


	cy_mxs40_isr_v1_0
		#(.deepsleep_required(0),
		  .int_type(2'b10))
		SCB_IRQ
		 (.int_signal(intr_wire));



	cy_clock_v1_0
		#(.id("efb6f5cf-5cc6-44f7-afe3-f502cc057108/b68e5b9d-7828-482d-a282-930f990e3b3e"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("127877237.851662"),
		  .is_direct(0),
		  .is_digital(0))
		SCBCLK
		 (.clock_out(Net_847));


	wire [0:0] tmpFB_0__scl_net;
	electrical [0:0] tmpSIOVREF__scl_net;

	cy_mxs40_gpio_v1_0
		#(.id("efb6f5cf-5cc6-44f7-afe3-f502cc057108/69c3b5e8-b094-4d65-b96b-9f4f3a9a8641"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("4"),
		  .ibuf_enabled("1"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("B"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		scl
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__scl_net[0:0]}),
		  .io({scl_b}),
		  .siovref(tmpSIOVREF__scl_net));


	wire [0:0] tmpFB_0__sda_net;
	electrical [0:0] tmpSIOVREF__sda_net;

	cy_mxs40_gpio_v1_0
		#(.id("efb6f5cf-5cc6-44f7-afe3-f502cc057108/2aab8a93-e7dd-4bd4-8210-42652cd079c5"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("4"),
		  .ibuf_enabled("1"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("B"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		sda
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__sda_net[0:0]}),
		  .io({sda_b}),
		  .siovref(tmpSIOVREF__sda_net));




endmodule

// bIncludeDriverToComponent_v1_0(PDL_DRIVER_NAME=ble, PDL_DRIVER_REQ_VERSION=2.0.0, PDL_DRIVER_SUBGROUP=Stack library, PDL_DRIVER_VARIANT=Profile - Host CM0+ / Ctrl CM0+, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=bIncludeDriverToComponent_v1_0, CY_CONFIG_TITLE=IncludeBleLibs, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=Bluetooth:IncludeBleLibs, CY_INSTANCE_SHORT_NAME=IncludeBleLibs, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=ble, CY_PDL_DRIVER_REQ_VERSION=2.0.0, CY_PDL_DRIVER_SUBGROUP=Stack library, CY_PDL_DRIVER_VARIANT=Profile - Host CM0+ / Ctrl CM0+, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=Bluetooth_IncludeBleLibs, )
module bIncludeDriverToComponent_v1_0_3 ;





endmodule

// BLE_PDL_v2_0(AddQdepthPerConn=0, AutopopulateWhitelist=true, ConnectionCount=1, coresCount=0, EnableExternalLnaRxOutput=false, EnableExternalPaLnaOutput=false, EnableExternalPaTxOutput=false, EnableExternalPrepWriteBuff=false, EnableL2capLogicalChannels=true, EnableLinkLayerPrivacy=true, GapConfig=<?xml version="1.0" encoding="utf-16"?>\r\n<CyGapConfiguration_T2 xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">\r\n  <DeviceAddress>00A050000000</DeviceAddress>\r\n  <SiliconGeneratedAddress>true</SiliconGeneratedAddress>\r\n  <MtuSize>23</MtuSize>\r\n  <MaxTxPayloadSize>27</MaxTxPayloadSize>\r\n  <MaxRxPayloadSize>27</MaxRxPayloadSize>\r\n  <TxPowerLevelConnection>0</TxPowerLevelConnection>\r\n  <TxPowerLevelAdvScan>0</TxPowerLevelAdvScan>\r\n  <Le2Mbps>false</Le2Mbps>\r\n  <LePing>false</LePing>\r\n  <TxPowerCalRetention>false</TxPowerCalRetention>\r\n  <SecurityConfig>\r\n    <SecurityMode>SECURITY_MODE_1</SecurityMode>\r\n    <SecurityLevel>UNAUTHENTICATED</SecurityLevel>\r\n    <StrictPairing>false</StrictPairing>\r\n    <KeypressNotifications>false</KeypressNotifications>\r\n    <IOCapability>NO_INPUT_NO_OUTPUT</IOCapability>\r\n    <PairingMethod>JUST_WORKS</PairingMethod>\r\n    <Bonding>BOND</Bonding>\r\n    <BondListSize>16</BondListSize>\r\n    <WhitelistSize>16</WhitelistSize>\r\n    <EnableLinkLayerPrivacy>true</EnableLinkLayerPrivacy>\r\n    <ResolvingListSize>16</ResolvingListSize>\r\n    <EncryptionKeySize>16</EncryptionKeySize>\r\n  </SecurityConfig>\r\n  <AdditionalSecurityConfigList />\r\n  <PeripheralConfigList>\r\n    <CyPeripheralConfiguration>\r\n      <Name>Peripheral configuration 0</Name>\r\n      <GapRole>PERIPHERAL</GapRole>\r\n      <AdvertisementConfig>\r\n        <AdvScanMode>FAST_CONNECTION</AdvScanMode>\r\n        <AdvFastScanInterval>\r\n          <Minimum>20</Minimum>\r\n          <Maximum>30</Maximum>\r\n        </AdvFastScanInterval>\r\n        <AdvReducedScanInterval>\r\n          <Minimum>1000</Minimum>\r\n          <Maximum>10240</Maximum>\r\n        </AdvReducedScanInterval>\r\n        <AdvDiscoveryMode>LIMITED</AdvDiscoveryMode>\r\n        <AdvType>CONNECTABLE_UNDIRECTED</AdvType>\r\n        <AdvFilterPolicy>SCAN_REQUEST_ANY_CONNECT_REQUEST_ANY</AdvFilterPolicy>\r\n        <AdvChannelMap>ALL</AdvChannelMap>\r\n        <AdvFastTimeout>30</AdvFastTimeout>\r\n        <AdvReducedTimeout>150</AdvReducedTimeout>\r\n      </AdvertisementConfig>\r\n      <AdvertisementPacket>\r\n        <PacketType>ADVERTISEMENT</PacketType>\r\n        <Items>\r\n          <CyADStructure>\r\n            <ADType>1</ADType>\r\n            <ADData>05</ADData>\r\n          </CyADStructure>\r\n          <CyADStructure>\r\n            <ADType>9</ADType>\r\n            <ADData>4B:69:6E:6F:58:69:2D:30:30:30:30</ADData>\r\n          </CyADStructure>\r\n        </Items>\r\n        <IncludedServicesServiceUuid />\r\n        <IncludedServicesServiceSolicitation />\r\n        <IncludedServicesServiceData />\r\n      </AdvertisementPacket>\r\n      <ScanResponsePacket>\r\n        <PacketType>SCAN_RESPONSE</PacketType>\r\n        <Items />\r\n        <IncludedServicesServiceUuid />\r\n        <IncludedServicesServiceSolicitation />\r\n        <IncludedServicesServiceData />\r\n      </ScanResponsePacket>\r\n    </CyPeripheralConfiguration>\r\n  </PeripheralConfigList>\r\n  <CentralConfigList />\r\n  <BroadcasterConfigList />\r\n  <ObserverConfigList />\r\n  <MixedPeripheralBroadcasterConfigList>\r\n    <CyPeripheralConfiguration>\r\n      <Name>Peripheral configuration 0</Name>\r\n      <GapRole>PERIPHERAL</GapRole>\r\n      <AdvertisementConfig>\r\n        <AdvScanMode>FAST_CONNECTION</AdvScanMode>\r\n        <AdvFastScanInterval>\r\n          <Minimum>20</Minimum>\r\n          <Maximum>30</Maximum>\r\n        </AdvFastScanInterval>\r\n        <AdvReducedScanInterval>\r\n          <Minimum>1000</Minimum>\r\n          <Maximum>10240</Maximum>\r\n        </AdvReducedScanInterval>\r\n        <AdvDiscoveryMode>LIMITED</AdvDiscoveryMode>\r\n        <AdvType>CONNECTABLE_UNDIRECTED</AdvType>\r\n        <AdvFilterPolicy>SCAN_REQUEST_ANY_CONNECT_REQUEST_ANY</AdvFilterPolicy>\r\n        <AdvChannelMap>ALL</AdvChannelMap>\r\n        <AdvFastTimeout>30</AdvFastTimeout>\r\n        <AdvReducedTimeout>150</AdvReducedTimeout>\r\n      </AdvertisementConfig>\r\n      <AdvertisementPacket>\r\n        <PacketType>ADVERTISEMENT</PacketType>\r\n        <Items>\r\n          <CyADStructure>\r\n            <ADType>1</ADType>\r\n            <ADData>05</ADData>\r\n          </CyADStructure>\r\n          <CyADStructure>\r\n            <ADType>9</ADType>\r\n            <ADData>4B:69:6E:6F:58:69:2D:30:30:30:30</ADData>\r\n          </CyADStructure>\r\n        </Items>\r\n        <IncludedServicesServiceUuid />\r\n        <IncludedServicesServiceSolicitation />\r\n        <IncludedServicesServiceData />\r\n      </AdvertisementPacket>\r\n      <ScanResponsePacket>\r\n        <PacketType>SCAN_RESPONSE</PacketType>\r\n        <Items />\r\n        <IncludedServicesServiceUuid />\r\n        <IncludedServicesServiceSolicitation />\r\n        <IncludedServicesServiceData />\r\n      </ScanResponsePacket>\r\n    </CyPeripheralConfiguration>\r\n  </MixedPeripheralBroadcasterConfigList>\r\n  <MixedCentralObserverConfigList />\r\n  <GapRoles>\r\n    <CyEGapRole>PERIPHERAL</CyEGapRole>\r\n  </GapRoles>\r\n</CyGapConfiguration_T2>, HalBaudRate=115200, HalCtsEnable=true, HalCtsPolarity=0, HalOversampling=13, HalRtsEnable=true, HalRtsPolarity=0, HalRtsTriggerLevel=120, HciContrCore=1, HostCore=1, ImportFilePath=, KeypressNotifications=false, L2capMpsSize=23, L2capMtuSize=23, L2capNumChannels=1, L2capNumPsm=1, LE2Mbps=false, LLMaxRxPayloadSize=27, LLMaxTxPayloadSize=27, MaxAttrNoOfBuffer=0, MaxBondedDevices=16, MaxResolvableDevices=16, MaxWhitelistSize=16, Mode=0, PDL_PARAM=Csub="Core"  Cvariant="", ProfileConfig=<?xml version="1.0" encoding="utf-16"?>\r\n<Profile xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema" ID="1" DisplayName="GATT" Name="GATT" Type="org.bluetooth.profile.custom">\r\n  <CyProfileRole ID="2" DisplayName="Server" Name="Server">\r\n    <CyService ID="3" DisplayName="Generic Access" Name="Generic Access" Type="org.bluetooth.service.generic_access" UUID="1800">\r\n      <CyCharacteristic ID="4" DisplayName="Device Name" Name="Device Name" Type="org.bluetooth.characteristic.gap.device_name" UUID="2A00">\r\n        <Field Name="Name">\r\n          <DataFormat>utf8s</DataFormat>\r\n          <ByteLength>11</ByteLength>\r\n          <FillRequirement>C1</FillRequirement>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>KinoXi-0000</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="READ" Present="true" Mandatory="true" />\r\n          <Property Type="WRITE" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission>\r\n          <EncryptionPermissionWrite>ENCRYPTION_REQUIRED</EncryptionPermissionWrite>\r\n        </Permission>\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="5" DisplayName="Appearance" Name="Appearance" Type="org.bluetooth.characteristic.gap.appearance" UUID="2A01">\r\n        <Field Name="Category">\r\n          <DataFormat>16bit</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <FillRequirement>C1</FillRequirement>\r\n          <ValueType>ENUM</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="READ" Present="true" Mandatory="true" />\r\n        </Properties>\r\n        <Permission>\r\n          <EncryptionPermissionWrite>ENCRYPTION_REQUIRED</EncryptionPermissionWrite>\r\n        </Permission>\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="6" DisplayName="Peripheral Preferred Connection Parameters" Name="Peripheral Preferred Connection Parameters" Type="org.bluetooth.characteristic.gap.peripheral_preferred_connection_parameters" UUID="2A04">\r\n        <Field Name="Minimum Connection Interval">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>6</Minimum>\r\n            <Maximum>3200</Maximum>\r\n          </Range>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0x0006</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Field Name="Maximum Connection Interval">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>6</Minimum>\r\n            <Maximum>3200</Maximum>\r\n          </Range>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0x0028</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Field Name="Slave Latency">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>0</Minimum>\r\n            <Maximum>499</Maximum>\r\n          </Range>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Field Name="Connection Supervision Timeout Multiplier">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>10</Minimum>\r\n            <Maximum>3200</Maximum>\r\n          </Range>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0x03E8</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="READ" Present="true" Mandatory="true" />\r\n        </Properties>\r\n        <Permission>\r\n          <EncryptionPermissionWrite>ENCRYPTION_REQUIRED</EncryptionPermissionWrite>\r\n        </Permission>\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="7" DisplayName="Central Address Resolution" Name="Central Address Resolution" Type="org.bluetooth.characteristic.gap.central_address_resolution" UUID="2AA6">\r\n        <Field Name="Central Address Resolution Support">\r\n          <DataFormat>uint8</DataFormat>\r\n          <ByteLength>1</ByteLength>\r\n          <ValueType>ENUM</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="READ" Present="true" Mandatory="true" />\r\n        </Properties>\r\n        <Permission>\r\n          <EncryptionPermissionWrite>ENCRYPTION_REQUIRED</EncryptionPermissionWrite>\r\n        </Permission>\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="8" DisplayName="Resolvable Private Address Only" Name="Resolvable Private Address Only" Type="org.bluetooth.characteristic.gap.resolvable_private_address_only" UUID="2AC9">\r\n        <Field Name="Resolvable Private Address Only">\r\n          <DataFormat>uint8</DataFormat>\r\n          <ByteLength>1</ByteLength>\r\n          <ValueType>ENUM</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="READ" Present="true" Mandatory="true" />\r\n        </Properties>\r\n        <Permission>\r\n          <EncryptionPermissionWrite>ENCRYPTION_REQUIRED</EncryptionPermissionWrite>\r\n        </Permission>\r\n      </CyCharacteristic>\r\n      <Declaration>PrimarySingleInstance</Declaration>\r\n      <IncludedServices />\r\n    </CyService>\r\n    <CyService ID="9" DisplayName="Generic Attribute" Name="Generic Attribute" Type="org.bluetooth.service.generic_attribute" UUID="1801">\r\n      <CyCharacteristic ID="10" DisplayName="Service Changed" Name="Service Changed" Type="org.bluetooth.characteristic.gatt.service_changed" UUID="2A05">\r\n        <CyDescriptor ID="11" DisplayName="Client Characteristic Configuration" Name="Client Characteristic Configuration" Type="org.bluetooth.descriptor.gatt.client_characteristic_configuration" UUID="2902">\r\n          <Field Name="Properties">\r\n            <DataFormat>16bit</DataFormat>\r\n            <ByteLength>2</ByteLength>\r\n            <Range>\r\n              <IsDeclared>true</IsDeclared>\r\n              <Minimum>0</Minimum>\r\n              <Maximum>3</Maximum>\r\n            </Range>\r\n            <ValueType>BITFIELD</ValueType>\r\n            <Bit>\r\n              <Index>0</Index>\r\n              <Size>1</Size>\r\n              <Value>0</Value>\r\n              <Enumerations>\r\n                <Enumeration key="0" value="Notifications disabled" />\r\n                <Enumeration key="1" value="Notifications enabled" />\r\n              </Enumerations>\r\n            </Bit>\r\n            <Bit>\r\n              <Index>1</Index>\r\n              <Size>1</Size>\r\n              <Value>0</Value>\r\n              <Enumerations>\r\n                <Enumeration key="0" value="Indications disabled" />\r\n                <Enumeration key="1" value="Indications enabled" />\r\n              </Enumerations>\r\n            </Bit>\r\n            <ArrayValue />\r\n          </Field>\r\n          <Properties>\r\n            <Property Type="READ" Present="true" Mandatory="true" />\r\n            <Property Type="WRITE" Present="true" Mandatory="true" />\r\n          </Properties>\r\n          <Permission>\r\n            <AccessPermission>READ_WRITE</AccessPermission>\r\n            <EncryptionPermissionWrite>ENCRYPTION_REQUIRED</EncryptionPermissionWrite>\r\n          </Permission>\r\n        </CyDescriptor>\r\n        <Field Name="Start of Affected Attribute Handle Range">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>1</Minimum>\r\n            <Maximum>65535</Maximum>\r\n          </Range>\r\n          <ValueType>BASIC</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Field Name="End of Affected Attribute Handle Range">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>1</Minimum>\r\n            <Maximum>65535</Maximum>\r\n          </Range>\r\n          <ValueType>BASIC</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="INDICATE" Present="true" Mandatory="true" />\r\n        </Properties>\r\n        <Permission>\r\n          <AccessPermission>NONE</AccessPermission>\r\n          <EncryptionPermissionWrite>ENCRYPTION_REQUIRED</EncryptionPermissionWrite>\r\n        </Permission>\r\n      </CyCharacteristic>\r\n      <Declaration>PrimarySingleInstance</Declaration>\r\n      <IncludedServices />\r\n    </CyService>\r\n    <CyService ID="22" DisplayName="Device Interface" Name="Custom Service" Type="org.bluetooth.service.custom" UUID="185E">\r\n      <CyCharacteristic ID="23" DisplayName="Inbound" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="7C1B">\r\n        <Field Name="Serial Data">\r\n          <DataFormat>uint8</DataFormat>\r\n          <ByteLength>1</ByteLength>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0x11</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission>\r\n          <AccessPermission>WRITE</AccessPermission>\r\n          <EncryptionPermissionRead>ENCRYPTION_REQUIRED</EncryptionPermissionRead>\r\n          <EncryptionPermissionWrite>ENCRYPTION_REQUIRED</EncryptionPermissionWrite>\r\n        </Permission>\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="25" DisplayName="Outbound" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="B6DB">\r\n        <CyDescriptor ID="27" DisplayName="Client Characteristic Configuration" Name="Client Characteristic Configuration" Type="org.bluetooth.descriptor.gatt.client_characteristic_configuration" UUID="2902">\r\n          <Field Name="Properties">\r\n            <DataFormat>16bit</DataFormat>\r\n            <ByteLength>2</ByteLength>\r\n            <Range>\r\n              <IsDeclared>true</IsDeclared>\r\n              <Minimum>0</Minimum>\r\n              <Maximum>3</Maximum>\r\n            </Range>\r\n            <ValueType>BITFIELD</ValueType>\r\n            <Bit>\r\n              <Index>0</Index>\r\n              <Size>1</Size>\r\n              <Value>1</Value>\r\n              <Enumerations>\r\n                <Enumeration key="0" value="Notifications disabled" />\r\n                <Enumeration key="1" value="Notifications enabled" />\r\n              </Enumerations>\r\n            </Bit>\r\n            <Bit>\r\n              <Index>1</Index>\r\n              <Size>1</Size>\r\n              <Value>0</Value>\r\n              <Enumerations>\r\n                <Enumeration key="0" value="Indications disabled" />\r\n                <Enumeration key="1" value="Indications enabled" />\r\n              </Enumerations>\r\n            </Bit>\r\n            <ArrayValue />\r\n          </Field>\r\n          <Properties>\r\n            <Property Type="READ" Present="true" Mandatory="false" />\r\n            <Property Type="WRITE" Present="true" Mandatory="false" />\r\n          </Properties>\r\n          <Permission>\r\n            <AccessPermission>READ_WRITE</AccessPermission>\r\n            <EncryptionPermissionWrite>ENCRYPTION_REQUIRED</EncryptionPermissionWrite>\r\n          </Permission>\r\n        </CyDescriptor>\r\n        <Field Name="Serial Data">\r\n          <DataFormat>uint8[]</DataFormat>\r\n          <ByteLength>1</ByteLength>\r\n          <ValueType>ARRAY</ValueType>\r\n          <GeneralValue>0x22</GeneralValue>\r\n          <ArrayValue>\r\n            <unsignedByte>34</unsignedByte>\r\n          </ArrayValue>\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="true" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission>\r\n          <EncryptionPermissionRead>ENCRYPTION_REQUIRED</EncryptionPermissionRead>\r\n          <EncryptionPermissionWrite>ENCRYPTION_REQUIRED</EncryptionPermissionWrite>\r\n        </Permission>\r\n      </CyCharacteristic>\r\n      <Declaration>Primary</Declaration>\r\n      <IncludedServices />\r\n    </CyService>\r\n    <CyService ID="28" DisplayName="Device Error Log" Name="Custom Service" Type="org.bluetooth.service.custom" UUID="823F">\r\n      <CyCharacteristic ID="29" DisplayName="Clear Log" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="2213">\r\n        <Field Name="Clear">\r\n          <DataFormat>uint8</DataFormat>\r\n          <ByteLength>1</ByteLength>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0x00</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission>\r\n          <AccessPermission>WRITE</AccessPermission>\r\n        </Permission>\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="31" DisplayName="Application Log" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="1151">\r\n        <CyDescriptor ID="33" DisplayName="Client Characteristic Configuration" Name="Client Characteristic Configuration" Type="org.bluetooth.descriptor.gatt.client_characteristic_configuration" UUID="2902">\r\n          <Field Name="Properties">\r\n            <DataFormat>16bit</DataFormat>\r\n            <ByteLength>2</ByteLength>\r\n            <Range>\r\n              <IsDeclared>true</IsDeclared>\r\n              <Minimum>0</Minimum>\r\n              <Maximum>3</Maximum>\r\n            </Range>\r\n            <ValueType>BITFIELD</ValueType>\r\n            <Bit>\r\n              <Index>0</Index>\r\n              <Size>1</Size>\r\n              <Value>1</Value>\r\n              <Enumerations>\r\n                <Enumeration key="0" value="Notifications disabled" />\r\n                <Enumeration key="1" value="Notifications enabled" />\r\n              </Enumerations>\r\n            </Bit>\r\n            <Bit>\r\n              <Index>1</Index>\r\n              <Size>1</Size>\r\n              <Value>0</Value>\r\n              <Enumerations>\r\n                <Enumeration key="0" value="Indications disabled" />\r\n                <Enumeration key="1" value="Indications enabled" />\r\n              </Enumerations>\r\n            </Bit>\r\n            <ArrayValue />\r\n          </Field>\r\n          <Properties>\r\n            <Property Type="READ" Present="true" Mandatory="false" />\r\n            <Property Type="WRITE" Present="true" Mandatory="false" />\r\n          </Properties>\r\n          <Permission>\r\n            <AccessPermission>READ_WRITE</AccessPermission>\r\n          </Permission>\r\n        </CyDescriptor>\r\n        <Field Name="Log">\r\n          <DataFormat>uint8[]</DataFormat>\r\n          <ByteLength>256</ByteLength>\r\n          <ValueType>ARRAY</ValueType>\r\n          <GeneralValue>0x11</GeneralValue>\r\n          <ArrayValue>\r\n            <unsignedByte>17</unsignedByte>\r\n          </ArrayValue>\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="true" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="34" DisplayName="Kinos Log" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="1152">\r\n        <CyDescriptor ID="35" DisplayName="Client Characteristic Configuration" Name="Client Characteristic Configuration" Type="org.bluetooth.descriptor.gatt.client_characteristic_configuration" UUID="2902">\r\n          <Field Name="Properties">\r\n            <DataFormat>16bit</DataFormat>\r\n            <ByteLength>2</ByteLength>\r\n            <Range>\r\n              <IsDeclared>true</IsDeclared>\r\n              <Minimum>0</Minimum>\r\n              <Maximum>3</Maximum>\r\n            </Range>\r\n            <ValueType>BITFIELD</ValueType>\r\n            <Bit>\r\n              <Index>0</Index>\r\n              <Size>1</Size>\r\n              <Value>1</Value>\r\n              <Enumerations>\r\n                <Enumeration key="0" value="Notifications disabled" />\r\n                <Enumeration key="1" value="Notifications enabled" />\r\n              </Enumerations>\r\n            </Bit>\r\n            <Bit>\r\n              <Index>1</Index>\r\n              <Size>1</Size>\r\n              <Value>0</Value>\r\n              <Enumerations>\r\n                <Enumeration key="0" value="Indications disabled" />\r\n                <Enumeration key="1" value="Indications enabled" />\r\n              </Enumerations>\r\n            </Bit>\r\n            <ArrayValue />\r\n          </Field>\r\n          <Properties>\r\n            <Property Type="READ" Present="true" Mandatory="false" />\r\n            <Property Type="WRITE" Present="true" Mandatory="false" />\r\n          </Properties>\r\n          <Permission>\r\n            <AccessPermission>READ_WRITE</AccessPermission>\r\n          </Permission>\r\n        </CyDescriptor>\r\n        <Field Name="Log">\r\n          <DataFormat>uint8[]</DataFormat>\r\n          <ByteLength>256</ByteLength>\r\n          <ValueType>ARRAY</ValueType>\r\n          <GeneralValue>0x22</GeneralValue>\r\n          <ArrayValue>\r\n            <unsignedByte>34</unsignedByte>\r\n          </ArrayValue>\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="true" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <Declaration>Primary</Declaration>\r\n      <IncludedServices />\r\n    </CyService>\r\n    <CyService ID="36" DisplayName="Device Use Profile" Name="Custom Service" Type="org.bluetooth.service.custom" UUID="6DAE">\r\n      <CyCharacteristic ID="39" DisplayName="Clear Log" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="AB5F">\r\n        <Field Name="Clear">\r\n          <DataFormat>uint8</DataFormat>\r\n          <ByteLength>1</ByteLength>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0x00</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission>\r\n          <AccessPermission>WRITE</AccessPermission>\r\n        </Permission>\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="41" DisplayName="Use Log" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="BD0C">\r\n        <Field Name="Log">\r\n          <DataFormat>uint8[]</DataFormat>\r\n          <ByteLength>80</ByteLength>\r\n          <ValueType>ARRAY</ValueType>\r\n          <GeneralValue>0x11</GeneralValue>\r\n          <ArrayValue>\r\n            <unsignedByte>17</unsignedByte>\r\n          </ArrayValue>\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <Declaration>Primary</Declaration>\r\n      <IncludedServices />\r\n    </CyService>\r\n    <RoleType>SERVER</RoleType>\r\n  </CyProfileRole>\r\n  <CyProfileRole ID="12" DisplayName="Client" Name="Client">\r\n    <CyService ID="13" DisplayName="Generic Access" Name="Generic Access" Type="org.bluetooth.service.generic_access" UUID="1800">\r\n      <CyCharacteristic ID="14" DisplayName="Device Name" Name="Device Name" Type="org.bluetooth.characteristic.gap.device_name" UUID="2A00">\r\n        <Field Name="Name">\r\n          <DataFormat>utf8s</DataFormat>\r\n          <ByteLength>0</ByteLength>\r\n          <FillRequirement>C1</FillRequirement>\r\n          <ValueType>BASIC</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="READ" Present="true" Mandatory="true" />\r\n          <Property Type="WRITE" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission>\r\n          <EncryptionPermissionWrite>ENCRYPTION_REQUIRED</EncryptionPermissionWrite>\r\n        </Permission>\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="15" DisplayName="Appearance" Name="Appearance" Type="org.bluetooth.characteristic.gap.appearance" UUID="2A01">\r\n        <Field Name="Category">\r\n          <DataFormat>16bit</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <FillRequirement>C1</FillRequirement>\r\n          <ValueType>ENUM</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="READ" Present="true" Mandatory="true" />\r\n        </Properties>\r\n        <Permission>\r\n          <EncryptionPermissionWrite>ENCRYPTION_REQUIRED</EncryptionPermissionWrite>\r\n        </Permission>\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="16" DisplayName="Peripheral Preferred Connection Parameters" Name="Peripheral Preferred Connection Parameters" Type="org.bluetooth.characteristic.gap.peripheral_preferred_connection_parameters" UUID="2A04">\r\n        <Field Name="Minimum Connection Interval">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>6</Minimum>\r\n            <Maximum>3200</Maximum>\r\n          </Range>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0x0006</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Field Name="Maximum Connection Interval">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>6</Minimum>\r\n            <Maximum>3200</Maximum>\r\n          </Range>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0x0028</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Field Name="Slave Latency">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>0</Minimum>\r\n            <Maximum>499</Maximum>\r\n          </Range>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Field Name="Connection Supervision Timeout Multiplier">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>10</Minimum>\r\n            <Maximum>3200</Maximum>\r\n          </Range>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0x03E8</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="READ" Present="true" Mandatory="true" />\r\n        </Properties>\r\n        <Permission>\r\n          <EncryptionPermissionWrite>ENCRYPTION_REQUIRED</EncryptionPermissionWrite>\r\n        </Permission>\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="17" DisplayName="Central Address Resolution" Name="Central Address Resolution" Type="org.bluetooth.characteristic.gap.central_address_resolution" UUID="2AA6">\r\n        <Field Name="Central Address Resolution Support">\r\n          <DataFormat>uint8</DataFormat>\r\n          <ByteLength>1</ByteLength>\r\n          <ValueType>ENUM</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="READ" Present="true" Mandatory="true" />\r\n        </Properties>\r\n        <Permission>\r\n          <EncryptionPermissionWrite>ENCRYPTION_REQUIRED</EncryptionPermissionWrite>\r\n        </Permission>\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="18" DisplayName="Resolvable Private Address Only" Name="Resolvable Private Address Only" Type="org.bluetooth.characteristic.gap.resolvable_private_address_only" UUID="2AC9">\r\n        <Field Name="Resolvable Private Address Only">\r\n          <DataFormat>uint8</DataFormat>\r\n          <ByteLength>1</ByteLength>\r\n          <ValueType>ENUM</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="READ" Present="true" Mandatory="true" />\r\n        </Properties>\r\n        <Permission>\r\n          <EncryptionPermissionWrite>ENCRYPTION_REQUIRED</EncryptionPermissionWrite>\r\n        </Permission>\r\n      </CyCharacteristic>\r\n      <Declaration>PrimarySingleInstance</Declaration>\r\n      <IncludedServices />\r\n    </CyService>\r\n    <CyService ID="19" DisplayName="Generic Attribute" Name="Generic Attribute" Type="org.bluetooth.service.generic_attribute" UUID="1801">\r\n      <CyCharacteristic ID="20" DisplayName="Service Changed" Name="Service Changed" Type="org.bluetooth.characteristic.gatt.service_changed" UUID="2A05">\r\n        <CyDescriptor ID="21" DisplayName="Client Characteristic Configuration" Name="Client Characteristic Configuration" Type="org.bluetooth.descriptor.gatt.client_characteristic_configuration" UUID="2902">\r\n          <Field Name="Properties">\r\n            <DataFormat>16bit</DataFormat>\r\n            <ByteLength>2</ByteLength>\r\n            <Range>\r\n              <IsDeclared>true</IsDeclared>\r\n              <Minimum>0</Minimum>\r\n              <Maximum>3</Maximum>\r\n            </Range>\r\n            <ValueType>BITFIELD</ValueType>\r\n            <Bit>\r\n              <Index>0</Index>\r\n              <Size>1</Size>\r\n              <Value>0</Value>\r\n              <Enumerations>\r\n                <Enumeration key="0" value="Notifications disabled" />\r\n                <Enumeration key="1" value="Notifications enabled" />\r\n              </Enumerations>\r\n            </Bit>\r\n            <Bit>\r\n              <Index>1</Index>\r\n              <Size>1</Size>\r\n              <Value>0</Value>\r\n              <Enumerations>\r\n                <Enumeration key="0" value="Indications disabled" />\r\n                <Enumeration key="1" value="Indications enabled" />\r\n              </Enumerations>\r\n            </Bit>\r\n            <ArrayValue />\r\n          </Field>\r\n          <Properties>\r\n            <Property Type="READ" Present="true" Mandatory="true" />\r\n            <Property Type="WRITE" Present="true" Mandatory="true" />\r\n          </Properties>\r\n          <Permission>\r\n            <AccessPermission>READ_WRITE</AccessPermission>\r\n            <EncryptionPermissionWrite>ENCRYPTION_REQUIRED</EncryptionPermissionWrite>\r\n          </Permission>\r\n        </CyDescriptor>\r\n        <Field Name="Start of Affected Attribute Handle Range">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>1</Minimum>\r\n            <Maximum>65535</Maximum>\r\n          </Range>\r\n          <ValueType>BASIC</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Field Name="End of Affected Attribute Handle Range">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>1</Minimum>\r\n            <Maximum>65535</Maximum>\r\n          </Range>\r\n          <ValueType>BASIC</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="INDICATE" Present="true" Mandatory="true" />\r\n        </Properties>\r\n        <Permission>\r\n          <AccessPermission>NONE</AccessPermission>\r\n          <EncryptionPermissionWrite>ENCRYPTION_REQUIRED</EncryptionPermissionWrite>\r\n        </Permission>\r\n      </CyCharacteristic>\r\n      <Declaration>PrimarySingleInstance</Declaration>\r\n      <IncludedServices />\r\n    </CyService>\r\n    <RoleType>CLIENT</RoleType>\r\n  </CyProfileRole>\r\n  <ClientInstCount>0</ClientInstCount>\r\n</Profile>, RadioPowerCalibration=false, SharingMode=0, SmartMeshConfig=, SmartMeshMode=false, StackMode=3, StrictPairing=false, UseDeepSleep=true, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=BLE_PDL_v2_0, CY_CONFIG_TITLE=Bluetooth, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=BLE_PDL_v2_0.pdf, CY_FITTER_NAME=Bluetooth, CY_INSTANCE_SHORT_NAME=Bluetooth, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=ble, CY_PDL_DRIVER_REQ_VERSION=2.0.0, CY_PDL_DRIVER_SUBGROUP=Core, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=Bluetooth, )
module BLE_PDL_v2_0_4 (
    pa_tx_en,
    lna_rx_en,
    pa_lna_en);
    output      pa_tx_en;
    output      lna_rx_en;
    output      pa_lna_en;


          wire  Net_66;
          wire  Net_65;
          wire  Net_64;
          wire  Net_63;
          wire  Net_62;
          wire  Net_61;
          wire  Net_60;
          wire  Net_59;
          wire  Net_58;
          wire  Net_52;
          wire  Net_43;
          wire  Net_42;
          wire  Net_41;
          wire  Net_40;
          wire  Net_39;
          wire  Net_38;
          wire  Net_37;
          wire  Net_36;
          wire  Net_3;
          wire  Net_2;
          wire  Net_1;

    cy_mxs40_ble_v1_0 cy_mxs40_ble (
        .ext_pa_lna_chip_en_out(pa_lna_en),
        .ext_lna_rx_ctl_out(lna_rx_en),
        .ext_pa_tx_ctl_out(pa_tx_en),
        .interrupt(Net_1));
    defparam cy_mxs40_ble.low_power = 1;


	cy_mxs40_isr_v1_0
		#(.deepsleep_required(1),
		  .int_type(2'b10))
		bless_isr
		 (.int_signal(Net_1));


    bIncludeDriverToComponent_v1_0_3 IncludeBleLibs ();



endmodule

// Component: not_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\not_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\not_v1_0\not_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\not_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\not_v1_0\not_v1_0.v"
`endif

// TCPWM_PWM_PDL_v1_0(ClockPrescaler=0, Compare0=50, Compare1=16384, CountInput=7, CountInputMasked=3, DeadClocks=0, EnableCompareSwap=false, EnablePeriodSwap=false, InterruptSource=0, InvertPwm=false, InvertPwm_n=false, KillInput=7, KillInputMasked=3, KillMode=2, Period0=255, Period1=32768, PwmAlignment=0, PwmMode=4, ReloadInput=7, ReloadInputMasked=3, Resolution=32, RunMode=0, StartInput=7, StartInputMasked=3, SwapInput=7, SwapInputMasked=3, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=TCPWM_PWM_PDL_v1_0, CY_CONFIG_TITLE=LightOutputC, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=LightOutputC, CY_INSTANCE_SHORT_NAME=LightOutputC, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=tcpwm, CY_PDL_DRIVER_REQ_VERSION=1.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=LightOutputC, )
module TCPWM_PWM_PDL_v1_0_5 (
    kill,
    reload,
    start,
    count,
    swap,
    interrupt,
    ovrflw,
    undrflw,
    compare,
    clock,
    pwm,
    pwm_n);
    input       kill;
    input       reload;
    input       start;
    input       count;
    input       swap;
    output      interrupt;
    output      ovrflw;
    output      undrflw;
    output      compare;
    input       clock;
    output      pwm;
    output      pwm_n;



    cy_mxs40_tcpwm_v1_0 TCPWM (
        .clock(clock),
        .capture(swap),
        .count(count),
        .reload(reload),
        .stop(kill),
        .start(start),
        .tr_underflow(undrflw),
        .tr_compare_match(compare),
        .tr_overflow(ovrflw),
        .line_compl(pwm_n),
        .line(pwm),
        .interrupt(interrupt));
    defparam TCPWM.exact_width = 0;
    defparam TCPWM.width = 32;



endmodule

// TCPWM_PWM_PDL_v1_0(ClockPrescaler=0, Compare0=50, Compare1=16384, CountInput=7, CountInputMasked=3, DeadClocks=0, EnableCompareSwap=false, EnablePeriodSwap=false, InterruptSource=0, InvertPwm=false, InvertPwm_n=false, KillInput=7, KillInputMasked=3, KillMode=2, Period0=255, Period1=32768, PwmAlignment=0, PwmMode=4, ReloadInput=7, ReloadInputMasked=3, Resolution=32, RunMode=0, StartInput=7, StartInputMasked=3, SwapInput=7, SwapInputMasked=3, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=TCPWM_PWM_PDL_v1_0, CY_CONFIG_TITLE=LightOutputA, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=LightOutputA, CY_INSTANCE_SHORT_NAME=LightOutputA, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=tcpwm, CY_PDL_DRIVER_REQ_VERSION=1.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=LightOutputA, )
module TCPWM_PWM_PDL_v1_0_6 (
    kill,
    reload,
    start,
    count,
    swap,
    interrupt,
    ovrflw,
    undrflw,
    compare,
    clock,
    pwm,
    pwm_n);
    input       kill;
    input       reload;
    input       start;
    input       count;
    input       swap;
    output      interrupt;
    output      ovrflw;
    output      undrflw;
    output      compare;
    input       clock;
    output      pwm;
    output      pwm_n;



    cy_mxs40_tcpwm_v1_0 TCPWM (
        .clock(clock),
        .capture(swap),
        .count(count),
        .reload(reload),
        .stop(kill),
        .start(start),
        .tr_underflow(undrflw),
        .tr_compare_match(compare),
        .tr_overflow(ovrflw),
        .line_compl(pwm_n),
        .line(pwm),
        .interrupt(interrupt));
    defparam TCPWM.exact_width = 0;
    defparam TCPWM.width = 32;



endmodule

// TCPWM_Counter_PDL_v1_0(CaptureInput=7, CaptureInputMasked=3, ClockPrescaler=0, Compare0=16384, Compare1=16384, CompareOrCapture=2, CountDirection=0, CountInput=7, CountInputMasked=3, EnableCompareSwap=false, InterruptSource=1, Period=42, ReloadInput=7, ReloadInputMasked=3, Resolution=16, RunMode=0, StartInput=7, StartInputMasked=3, StopInput=7, StopInputMasked=3, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=TCPWM_Counter_PDL_v1_0, CY_CONFIG_TITLE=LightTimer, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=LightTimer, CY_INSTANCE_SHORT_NAME=LightTimer, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=tcpwm, CY_PDL_DRIVER_REQ_VERSION=1.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=LightTimer, )
module TCPWM_Counter_PDL_v1_0_7 (
    stop,
    reload,
    start,
    count,
    capture,
    interrupt,
    ovrflw,
    undrflw,
    compare,
    clock);
    input       stop;
    input       reload;
    input       start;
    input       count;
    input       capture;
    output      interrupt;
    output      ovrflw;
    output      undrflw;
    output      compare;
    input       clock;


          wire  Net_2;
          wire  Net_1;

    cy_mxs40_tcpwm_v1_0 TCPWM (
        .clock(clock),
        .capture(capture),
        .count(count),
        .reload(reload),
        .stop(stop),
        .start(start),
        .tr_underflow(undrflw),
        .tr_compare_match(compare),
        .tr_overflow(ovrflw),
        .line_compl(Net_1),
        .line(Net_2),
        .interrupt(interrupt));
    defparam TCPWM.exact_width = 0;
    defparam TCPWM.width = 16;



endmodule

// TCPWM_PWM_PDL_v1_0(ClockPrescaler=0, Compare0=50, Compare1=16384, CountInput=7, CountInputMasked=3, DeadClocks=0, EnableCompareSwap=false, EnablePeriodSwap=false, InterruptSource=0, InvertPwm=false, InvertPwm_n=false, KillInput=7, KillInputMasked=3, KillMode=2, Period0=255, Period1=32768, PwmAlignment=0, PwmMode=4, ReloadInput=7, ReloadInputMasked=3, Resolution=32, RunMode=0, StartInput=7, StartInputMasked=3, SwapInput=7, SwapInputMasked=3, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=TCPWM_PWM_PDL_v1_0, CY_CONFIG_TITLE=LightOutputB, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=LightOutputB, CY_INSTANCE_SHORT_NAME=LightOutputB, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=tcpwm, CY_PDL_DRIVER_REQ_VERSION=1.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=LightOutputB, )
module TCPWM_PWM_PDL_v1_0_8 (
    kill,
    reload,
    start,
    count,
    swap,
    interrupt,
    ovrflw,
    undrflw,
    compare,
    clock,
    pwm,
    pwm_n);
    input       kill;
    input       reload;
    input       start;
    input       count;
    input       swap;
    output      interrupt;
    output      ovrflw;
    output      undrflw;
    output      compare;
    input       clock;
    output      pwm;
    output      pwm_n;



    cy_mxs40_tcpwm_v1_0 TCPWM (
        .clock(clock),
        .capture(swap),
        .count(count),
        .reload(reload),
        .stop(kill),
        .start(start),
        .tr_underflow(undrflw),
        .tr_compare_match(compare),
        .tr_overflow(ovrflw),
        .line_compl(pwm_n),
        .line(pwm),
        .interrupt(interrupt));
    defparam TCPWM.exact_width = 0;
    defparam TCPWM.width = 32;



endmodule

// TCPWM_PWM_PDL_v1_0(ClockPrescaler=0, Compare0=50, Compare1=16384, CountInput=7, CountInputMasked=3, DeadClocks=0, EnableCompareSwap=false, EnablePeriodSwap=false, InterruptSource=0, InvertPwm=false, InvertPwm_n=false, KillInput=7, KillInputMasked=3, KillMode=2, Period0=100, Period1=32768, PwmAlignment=0, PwmMode=4, ReloadInput=7, ReloadInputMasked=3, Resolution=32, RunMode=0, StartInput=7, StartInputMasked=3, SwapInput=7, SwapInputMasked=3, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=TCPWM_PWM_PDL_v1_0, CY_CONFIG_TITLE=MotorOutput, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=MotorOutput, CY_INSTANCE_SHORT_NAME=MotorOutput, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=tcpwm, CY_PDL_DRIVER_REQ_VERSION=1.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=MotorOutput, )
module TCPWM_PWM_PDL_v1_0_9 (
    kill,
    reload,
    start,
    count,
    swap,
    interrupt,
    ovrflw,
    undrflw,
    compare,
    clock,
    pwm,
    pwm_n);
    input       kill;
    input       reload;
    input       start;
    input       count;
    input       swap;
    output      interrupt;
    output      ovrflw;
    output      undrflw;
    output      compare;
    input       clock;
    output      pwm;
    output      pwm_n;



    cy_mxs40_tcpwm_v1_0 TCPWM (
        .clock(clock),
        .capture(swap),
        .count(count),
        .reload(reload),
        .stop(kill),
        .start(start),
        .tr_underflow(undrflw),
        .tr_compare_match(compare),
        .tr_overflow(ovrflw),
        .line_compl(pwm_n),
        .line(pwm),
        .interrupt(interrupt));
    defparam TCPWM.exact_width = 0;
    defparam TCPWM.width = 32;



endmodule

// TCPWM_Counter_PDL_v1_0(CaptureInput=7, CaptureInputMasked=3, ClockPrescaler=0, Compare0=16384, Compare1=16384, CompareOrCapture=2, CountDirection=0, CountInput=7, CountInputMasked=3, EnableCompareSwap=false, InterruptSource=1, Period=90, ReloadInput=7, ReloadInputMasked=3, Resolution=16, RunMode=0, StartInput=7, StartInputMasked=3, StopInput=7, StopInputMasked=3, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=TCPWM_Counter_PDL_v1_0, CY_CONFIG_TITLE=MotorTimer, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=MotorTimer, CY_INSTANCE_SHORT_NAME=MotorTimer, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=tcpwm, CY_PDL_DRIVER_REQ_VERSION=1.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=MotorTimer, )
module TCPWM_Counter_PDL_v1_0_10 (
    stop,
    reload,
    start,
    count,
    capture,
    interrupt,
    ovrflw,
    undrflw,
    compare,
    clock);
    input       stop;
    input       reload;
    input       start;
    input       count;
    input       capture;
    output      interrupt;
    output      ovrflw;
    output      undrflw;
    output      compare;
    input       clock;


          wire  Net_2;
          wire  Net_1;

    cy_mxs40_tcpwm_v1_0 TCPWM (
        .clock(clock),
        .capture(capture),
        .count(count),
        .reload(reload),
        .stop(stop),
        .start(start),
        .tr_underflow(undrflw),
        .tr_compare_match(compare),
        .tr_overflow(ovrflw),
        .line_compl(Net_1),
        .line(Net_2),
        .interrupt(interrupt));
    defparam TCPWM.exact_width = 0;
    defparam TCPWM.width = 16;



endmodule

// TCPWM_PWM_PDL_v1_0(ClockPrescaler=0, Compare0=50, Compare1=16384, CountInput=7, CountInputMasked=3, DeadClocks=0, EnableCompareSwap=false, EnablePeriodSwap=false, InterruptSource=0, InvertPwm=false, InvertPwm_n=false, KillInput=7, KillInputMasked=3, KillMode=2, Period0=250, Period1=32768, PwmAlignment=0, PwmMode=4, ReloadInput=7, ReloadInputMasked=3, Resolution=16, RunMode=0, StartInput=7, StartInputMasked=3, SwapInput=7, SwapInputMasked=3, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=TCPWM_PWM_PDL_v1_0, CY_CONFIG_TITLE=ChimeOutput, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=ChimeOutput, CY_INSTANCE_SHORT_NAME=ChimeOutput, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=tcpwm, CY_PDL_DRIVER_REQ_VERSION=1.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=ChimeOutput, )
module TCPWM_PWM_PDL_v1_0_11 (
    kill,
    reload,
    start,
    count,
    swap,
    interrupt,
    ovrflw,
    undrflw,
    compare,
    clock,
    pwm,
    pwm_n);
    input       kill;
    input       reload;
    input       start;
    input       count;
    input       swap;
    output      interrupt;
    output      ovrflw;
    output      undrflw;
    output      compare;
    input       clock;
    output      pwm;
    output      pwm_n;



    cy_mxs40_tcpwm_v1_0 TCPWM (
        .clock(clock),
        .capture(swap),
        .count(count),
        .reload(reload),
        .stop(kill),
        .start(start),
        .tr_underflow(undrflw),
        .tr_compare_match(compare),
        .tr_overflow(ovrflw),
        .line_compl(pwm_n),
        .line(pwm),
        .interrupt(interrupt));
    defparam TCPWM.exact_width = 0;
    defparam TCPWM.width = 16;



endmodule

// TCPWM_Counter_PDL_v1_0(CaptureInput=7, CaptureInputMasked=3, ClockPrescaler=0, Compare0=16384, Compare1=16384, CompareOrCapture=2, CountDirection=1, CountInput=7, CountInputMasked=3, EnableCompareSwap=false, InterruptSource=1, Period=64, ReloadInput=7, ReloadInputMasked=3, Resolution=16, RunMode=0, StartInput=7, StartInputMasked=3, StopInput=7, StopInputMasked=3, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=TCPWM_Counter_PDL_v1_0, CY_CONFIG_TITLE=ChimeTimer, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=ChimeTimer, CY_INSTANCE_SHORT_NAME=ChimeTimer, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=tcpwm, CY_PDL_DRIVER_REQ_VERSION=1.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=ChimeTimer, )
module TCPWM_Counter_PDL_v1_0_12 (
    stop,
    reload,
    start,
    count,
    capture,
    interrupt,
    ovrflw,
    undrflw,
    compare,
    clock);
    input       stop;
    input       reload;
    input       start;
    input       count;
    input       capture;
    output      interrupt;
    output      ovrflw;
    output      undrflw;
    output      compare;
    input       clock;


          wire  Net_2;
          wire  Net_1;

    cy_mxs40_tcpwm_v1_0 TCPWM (
        .clock(clock),
        .capture(capture),
        .count(count),
        .reload(reload),
        .stop(stop),
        .start(start),
        .tr_underflow(undrflw),
        .tr_compare_match(compare),
        .tr_overflow(ovrflw),
        .line_compl(Net_1),
        .line(Net_2),
        .interrupt(interrupt));
    defparam TCPWM.exact_width = 0;
    defparam TCPWM.width = 16;



endmodule

// RTC_PDL_v2_0(DateFormat=0, DaylightSavingsTimeEn=false, DayOfMonth=20, DayOfMonthDstStart=22, DayOfMonthDstStop=22, DayOfWeek=1, DayOfWeekDstStart=1, DayOfWeekDstStop=1, DstDateType=0, EnableRtcInterrupt=false, Hour=0, HoursDstStart=0, HoursDstStop=0, Month=1, MonthDstStart=3, MonthDstStop=10, RemoveIntr=true, TimeFormat=0, TimeResetOnStart=false, WeekOfMonthDstStart=6, WeekOfMonthDstStop=6, Year=19, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=RTC_PDL_v2_0, CY_CONFIG_TITLE=RealTimeClock, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=RealTimeClock, CY_INSTANCE_SHORT_NAME=RealTimeClock, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=rtc, CY_PDL_DRIVER_REQ_VERSION=2.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=RealTimeClock, )
module RTC_PDL_v2_0_13 ;


          wire  Net_3;

    cy_mxs40_rtc_v1_0 RTC (
        .interrupt(Net_3));



endmodule

// Component: cy_analog_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_analog_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_analog_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`endif

// CapSense_v2_0(AdcAmuxbInputEnable=false, AdcAnalogStartupDelayUs=23, AdcAzEnable=true, AdcAzTime=5, AdcDedicatedChannels=0, AdcEnable=false, AdcMeasureMode=0, AdcPinAlias=Ch0, AdcResolution=10, AdcSelectAmuxBusChannel=0, AdcTotalChannels=0, AdcVref=-1, BallisticMultiplierEnable=false, BaselineType=0, BlockOffAfterScanEnable=false, Centroid4PtsEnable=false, ClickEnable=false, Csd0IdacGainV1=4, Csd0IdacGainV2=2, Csd0PinAlias=Proximity0_Sns0, Csd0PinCount=1, Csd0ShieldDelayV1=0, Csd0ShieldDelayV2=0, Csd0ShieldEnable=false, Csd0ShieldPrechargeSource=0, Csd0ShieldTankEnable=false, Csd0TotalShieldCount=1, Csd1IdacGainV1=4, Csd1IdacGainV2=2, Csd1PinAlias=, Csd1PinCount=0, Csd1ShieldDelayV1=0, Csd1ShieldDelayV2=0, Csd1ShieldEnable=false, Csd1ShieldPrechargeSource=0, Csd1ShieldTankEnable=false, Csd1TotalShieldCount=1, Csd2xEnable=false, CsdAnalogStartupDelayUs=23, CsdAutoZeroEnable=false, CsdAutoZeroTime=15, CsdCommonSenseClockEnable=false, CsdDedicatedIdacCompEnable=true, CsdDualIdacLevel=50, CsdEnable=true, CsdF1PMSwitchResLowEmiInit=1, CsdF1PMSwitchResLowEmiScan=0, CsdF2PTSwitchResLowEmiInit=1, CsdF2PTSwitchResLowEmiScan=0, CsdFineInitCycles=10, CsdHCAGSwitchResLowEmiInit=1, CsdHCAGSwitchResLowEmiScan=3, CsdHCAVSwitchResLowEmiInit=1, CsdHCAVSwitchResLowEmiScan=0, CsdHCBGSwitchResLowEmiInit=1, CsdHCBGSwitchResLowEmiScan=3, CsdHCBVSwitchResLowEmiInit=1, CsdHCBVSwitchResLowEmiScan=3, CsdIdacAutoCalibrateEnable=true, CsdIdacCompEnable=true, CsdIdacConfig=0, CsdInactiveSensorConnection=0, CsdInitSwitchRes=1, CsdMFSDividerOffsetF1=1, CsdMFSDividerOffsetF2=2, CsdModClockFreq=6250, CsdNoiseMetricEnable=false, CsdNoiseMetricThreshold=1, CsdPrescanSettlingTime=5, CsdRawCountCalibrationLevel=85, CsdSenseClockFreq=3125, CsdSenseClockSource=1, CsdSenseWidthLowEmi=10, CsdSensingMethod=0, CsdShieldSwitchRes=1, CsdSnsClockConstantR=1000, CsdTuningMode=3, CsdV2AnalogWakeupDelayUs=0, CsdVrefV2=-1, Csx0IdacGainV1=4, Csx0IdacGainV2=1, Csx0PinAliasRx=, Csx0PinCountRx=0, Csx1IdacGainV1=4, Csx1IdacGainV2=1, Csx1PinAliasRx=, Csx1PinCountRx=0, Csx2xEnable=false, CsxAnalogStartupDelayUs=23, CsxAutoZeroEnable=false, CsxAutoZeroTime=15, CsxCommonTxClockEnable=false, CsxEnable=false, CsxFineInitCycles=4, CsxIdacAutoCalibrateEnable=true, CsxIdacBitsUsedV1=8, CsxIdacBitsUsedV2=7, CsxInitShieldSwitchRes=2, CsxInitSwitchRes=1, CsxMaxFingers=1, CsxMaxLocalPeaks=5, CsxMFSDividerOffsetF1=1, CsxMFSDividerOffsetF2=2, CsxModClockFreq=25000, CsxMultiphaseTxEnable=false, CsxNoiseMetricEnable=false, CsxNoiseMetricThreshold=1, CsxPinAliasMptx=, CsxPinAliasRx=, CsxPinAliasTx=, CsxPinCountMptx=0, CsxPinCountRx=0, CsxPinCountTx=0, CsxRawCountCalibrationLevel=40, CsxScanShieldSwitchRes=0, CsxScanSwitchRes=0, CsxSkipAndOversampleNodes=false, CsxTxClockFreq=300, CsxTxClockSource=1, CustomDataStructSize=0, DoxygenMode=false, GestureEnable=false, GestureGlobalEnable=false, IrefSel=0, IsAdcSupported=true, IsCapSenseSupported=true, IsGestureSupported=true, LowBaselineResetSize=8, LpModeEn=false, MultiFreqScanEnable=false, NumCentroids=1, OffDebounceEnable=false, OneFingerEdgeSwipeEnable=false, OneFingerEdgeSwipeTimeoutInterval=2000, OneFingerFlickEnable=false, OneFingerRotateEnable=false, OneFingerScrollEnable=false, PosIirFilterCoeff=128, ProxAlpFilterCoeff=2, ProxAlpFilterEnable=false, ProxAverageFilterEnable=false, ProxAverageFilterSampleSize=4, ProxCustomFilterEnable=false, ProxIirFilterBaselineN=1, ProxIirFilterBaselineType=2, ProxIirFilterEnable=true, ProxIirFilterRawCountN=128, ProxIirFilterRawCountType=1, ProxMedianFilterEnable=false, RadialSliderPosIirResetThr=35, RegisterMapSelfTest=false, RegularAlpFilterCoeff=2, RegularAlpFilterEnable=false, RegularAverageFilterEnable=false, RegularAverageFilterSampleSize=4, RegularCustomFilterEnable=false, RegularIirFilterBaselineN=1, RegularIirFilterBaselineType=2, RegularIirFilterEnable=false, RegularIirFilterRawCountN=128, RegularIirFilterRawCountType=1, RegularMedianFilterEnable=false, SecondFinger5x5FilterEnable=false, SelfTestAnalogStartupDelayUs=23, SelfTestBaselineDuplicationEnable=true, SelfTestBaselineRawCountRangeEnable=true, SelfTestEnable=false, SelfTestExtCapEnable=true, SelfTestFineInitCycles=1, SelfTestGlobalCrcEnable=true, SelfTestIntCapEnable=true, SelfTestShCapEnable=true, SelfTestSns2SnsEnable=true, SelfTestSnsCapEnable=true, SelfTestSnsShortEnable=true, SelfTestVddaEnable=true, SelfTestVddaVref=-1, SelfTestWidgetCrcEnable=true, SensorAutoResetEnable=false, SensorAutoResetMethod=0, SensorAutoResetSamplesCount=1000, SliderMultiplierMethod=0, ThresholdSize=16, TimestampInterval=1, TouchpadDisplaySettings=, TouchpadMultiplierMethod=0, TouchProxThresholdCoeff=300, TunerLayoutPreferences=, TunerOptionsPreferences=, TunerViewPreferences=, TunerWidgetData=, TwoFingerScrollEnable=false, TwoFingerSettlingTime=3, TwoFingerZoomEnable=false, VddaValue=3.3, VrefSel=0, WidgetBaselineCoeffEnable=false, WidgetData=<?xml version="1.0" encoding="utf-16"?> <WidgetData xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">   <Widget id="Proximity0" type="Proximity" mode="CSD" block="CSD0" slot="0">     <Angle>0</Angle>     <FlippedX>false</FlippedX>     <FlippedY>false</FlippedY>     <Flipped2D>false</Flipped2D>     <ScaleFactor>1</ScaleFactor>     <Properties>       <FingerCap>0.2</FingerCap>       <Diplexing>false</Diplexing>       <MaxPosition>100</MaxPosition>       <MaxXPosition>100</MaxXPosition>       <MaxYPosition>100</MaxYPosition>       <PositionFilter>None</PositionFilter>       <MultiphaseTx>false</MultiphaseTx>       <SenseClockFreq>3125</SenseClockFreq>       <RowSenseClockFreq>3125</RowSenseClockFreq>       <TxClockFreq>300</TxClockFreq>       <IsxTxClockFreq>1000</IsxTxClockFreq>       <ScanResolution>_12</ScanResolution>       <NumConversions>100</NumConversions>       <IdacMod>         <Idac0>32</Idac0>         <Idac1>32</Idac1>         <Idac2>32</Idac2>       </IdacMod>       <RowIdacMod>         <Idac0>32</Idac0>         <Idac1>32</Idac1>         <Idac2>32</Idac2>       </RowIdacMod>       <FingerThreshold>100</FingerThreshold>       <ProxTouchThreshold>200</ProxTouchThreshold>       <NoiseThreshold>40</NoiseThreshold>       <NegNoiseThreshold>40</NegNoiseThreshold>       <LowBaselineReset>30</LowBaselineReset>       <BaselineReset>1000</BaselineReset>       <BaselineUpdateThreshold>100</BaselineUpdateThreshold>       <Hysteresis>15</Hysteresis>       <OnDebounce>3</OnDebounce>       <OffDebounce>3</OffDebounce>       <AlpOnThreshold>60</AlpOnThreshold>       <AlpOFFThreshold>20</AlpOFFThreshold>       <Velocity>2500</Velocity>       <MedianFilter>false</MedianFilter>       <IirFilter>false</IirFilter>       <IirFilterCoeff>128</IirFilterCoeff>       <AIirFilter>false</AIirFilter>       <AverageFilter>false</AverageFilter>       <JitterFilter>false</JitterFilter>       <BallisticMultiplier>false</BallisticMultiplier>       <AIirPositionMoveTh>3</AIirPositionMoveTh>       <AIirPositionSlowMoveTh>7</AIirPositionSlowMoveTh>       <AIirPositionFastMoveTh>12</AIirPositionFastMoveTh>       <AIirCoeffMaxLimit>60</AIirCoeffMaxLimit>       <AIirCoeffMinLimit>1</AIirCoeffMinLimit>       <AIirCoeffDivisor>64</AIirCoeffDivisor>       <CentroidType>Csd3x3</CentroidType>       <CrossCouplingPosTh>5</CrossCouplingPosTh>       <EdgeCorrectionEnable>true</EdgeCorrectionEnable>       <EdgeVirtualSensorTh>100</EdgeVirtualSensorTh>       <EdgePenultimateTh>100</EdgePenultimateTh>       <TwoFingerDetection>false</TwoFingerDetection>       <FastMovementMult>9</FastMovementMult>       <SlowMovementMult>2</SlowMovementMult>       <DivisorValue>4</DivisorValue>       <SpeedThresholdX>3</SpeedThresholdX>       <SpeedThresholdY>4</SpeedThresholdY>     </Properties>     <Gestures>       <Click>         <Enabled>false</Enabled>         <XMaxPosDisplacement>30</XMaxPosDisplacement>         <YMaxPosDisplacement>30</YMaxPosDisplacement>         <MaxPosDisplacement>30</MaxPosDisplacement>         <MaxRadius>20</MaxRadius>         <MaxDisplacement>20</MaxDisplacement>         <MinTouchInterval>10</MinTouchInterval>         <MaxTouchInterval>1000</MaxTouchInterval>         <OneFingerMinTouchDuration>10</OneFingerMinTouchDuration>         <OneFingerMaxTouchDuration>1000</OneFingerMaxTouchDuration>         <TwoFingerMinTouchDuration>100</TwoFingerMinTouchDuration>         <TwoFingerMaxTouchDuration>1000</TwoFingerMaxTouchDuration>       </Click>       <OneFingerScroll>         <Enabled>false</Enabled>         <Debounce>3</Debounce>         <XPosThreshold1>20</XPosThreshold1>         <YPosThreshold1>20</YPosThreshold1>         <PosThreshold1>20</PosThreshold1>         <ScrollStep1>3</ScrollStep1>         <XPosThreshold2>24</XPosThreshold2>         <YPosThreshold2>24</YPosThreshold2>         <F1_Scroll_PosThreshold2>20</F1_Scroll_PosThreshold2>         <ScrollStep2>5</ScrollStep2>         <XPosThreshold3>30</XPosThreshold3>         <YPosThreshold3>30</YPosThreshold3>         <PosThreshold3>20</PosThreshold3>         <ScrollStep3>7</ScrollStep3>         <XPosThreshold4>40</XPosThreshold4>         <YPosThreshold4>40</YPosThreshold4>         <PosThreshold4>20</PosThreshold4>         <ScrollStep4>9</ScrollStep4>         <XPosThreshold>50</XPosThreshold>         <YPosThreshold>50</YPosThreshold>         <PosThreshold>50</PosThreshold>         <CountLevel>Inert_Low</CountLevel>       </OneFingerScroll>       <TwoFingerScroll>         <Enabled>false</Enabled>         <Debounce>3</Debounce>         <XPosThreshold1>20</XPosThreshold1>         <YPosThreshold1>20</YPosThreshold1>         <PosThreshold1>20</PosThreshold1>         <ScrollStep1>3</ScrollStep1>         <XPosThreshold2>24</XPosThreshold2>         <YPosThreshold2>24</YPosThreshold2>         <PosThreshold2>24</PosThreshold2>         <ScrollStep2>5</ScrollStep2>         <XPosThreshold3>30</XPosThreshold3>         <YPosThreshold3>30</YPosThreshold3>         <PosThreshold3>30</PosThreshold3>         <ScrollStep3>7</ScrollStep3>         <XPosThreshold4>40</XPosThreshold4>         <YPosThreshold4>40</YPosThreshold4>         <PosThreshold4>40</PosThreshold4>         <ScrollStep4>9</ScrollStep4>         <XPosThreshold>50</XPosThreshold>         <YPosThreshold>50</YPosThreshold>         <PosThreshold>50</PosThreshold>         <CountLevel>Inert_Low</CountLevel>       </TwoFingerScroll>       <OneFingerFlick>         <Enabled>false</Enabled>         <XPosThreshold>20</XPosThreshold>         <YPosThreshold>20</YPosThreshold>         <PosThreshold>20</PosThreshold>         <MaxSampleInterval>80</MaxSampleInterval>       </OneFingerFlick>       <OneFingerEdgeSwipe>         <Enabled>false</Enabled>         <PosThreshold>100</PosThreshold>         <DetectionTime>100</DetectionTime>         <TimeoutInterval>2000</TimeoutInterval>         <TopAngleThreshold>45</TopAngleThreshold>         <BottomAngleThreshold>45</BottomAngleThreshold>         <DisamRegionWidth>5</DisamRegionWidth>       </OneFingerEdgeSwipe>       <TwoFingerZoom>         <Enabled>false</Enabled>         <XPosThreshold>8</XPosThreshold>         <YPosThreshold>8</YPosThreshold>         <PosThreshold>8</PosThreshold>         <Debounce>3</Debounce>         <ScrollZoomDebounce>5</ScrollZoomDebounce>       </TwoFingerZoom>       <OneFingerRotate>         <Enabled>false</Enabled>         <RotateDebounce>0</RotateDebounce>         <PosThreshold>8</PosThreshold>       </OneFingerRotate>     </Gestures>     <Sensors>       <Sensor id="Sns0">         <Properties>           <IdacComp>             <Idac0>32</Idac0>             <Idac1>32</Idac1>             <Idac2>32</Idac2>           </IdacComp>           <Idacs />           <UseDedicatedPin>true</UseDedicatedPin>           <GangedPins />         </Properties>       </Sensor>     </Sensors>   </Widget> </WidgetData>, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=CapSense_v2_0, CY_CONFIG_TITLE=CapSense, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=CapSense, CY_INSTANCE_SHORT_NAME=CapSense, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=CapSense, )
module CapSense_v2_0_14 ;


          wire  Net_609;
          wire  Net_849;
          wire  Net_822;
          wire  Net_821;
          wire [15:0] Net_828;
          wire  Net_819;
          wire  Net_818;
          wire  Net_817;
          wire  Net_845;
          wire  Net_815;
          wire  Net_814;
          wire  Net_813;
          wire  Net_851;
    electrical  Net_850;
          wire  Net_610;
          wire  Net_608;
          wire  Net_44;
    electrical  Net_34;
          wire  Net_1423;
          wire  Net_639;
          wire  Net_638;
          wire  Net_637;
          wire  Net_636;
          wire  Net_48;
          wire  Net_47;
          wire  Net_46;
          wire  Net_45;
          wire  Net_589;
    electrical  Net_314;
    electrical  Net_866;
    electrical [1:0] dedicated_io_bus;
    electrical  Net_846;
    electrical  Net_616;
    electrical  Net_82;
    electrical  Net_615;
    electrical  Net_324;
    electrical  Net_273;
    electrical  Net_848;
    electrical  Net_13;
    electrical  Net_847;
    electrical  Net_606;
          wire  Net_611;

	wire [0:0] tmpFB_0__Cmod_net;
	wire [0:0] tmpIO_0__Cmod_net;
	electrical [0:0] tmpSIOVREF__Cmod_net;

	cy_mxs40_gpio_v1_0
		#(.id("315c63aa-3ed5-4aed-96ad-b9fc4691d099/4db2e9d3-9f70-4f4e-a919-7eefada41863"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("0"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases("Cmod"),
		  .pin_mode("A"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		Cmod
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__Cmod_net[0:0]}),
		  .analog({Net_314}),
		  .io({tmpIO_0__Cmod_net[0:0]}),
		  .siovref(tmpSIOVREF__Cmod_net));


    ZeroTerminal ZeroTerminal_15 (
        .z(Net_589));

    cy_mxs40_csidac_v1_0 IDACMod (
        .iout(Net_606),
        .dsi_idac_leg1_en(Net_45),
        .dsi_idac_leg2_en(Net_46),
        .dsi_idac_leg3_en(Net_47),
        .dsi_idac_pol(Net_48));
    defparam IDACMod.leg3_needed = 0;

    cy_mxs40_csidac_v1_0 IDACComp (
        .iout(Net_866),
        .dsi_idac_leg1_en(Net_636),
        .dsi_idac_leg2_en(Net_637),
        .dsi_idac_leg3_en(Net_638),
        .dsi_idac_pol(Net_639));
    defparam IDACComp.leg3_needed = 1;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_45));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_46));

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_47));

    ZeroTerminal ZeroTerminal_4 (
        .z(Net_48));

    ZeroTerminal ZeroTerminal_5 (
        .z(Net_636));

    ZeroTerminal ZeroTerminal_6 (
        .z(Net_637));

    ZeroTerminal ZeroTerminal_7 (
        .z(Net_638));

    ZeroTerminal ZeroTerminal_8 (
        .z(Net_639));

    ZeroTerminal ZeroTerminal_14 (
        .z(Net_1423));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_34));

    ZeroTerminal ZeroTerminal_12 (
        .z(Net_44));

	// cy_analog_virtualmux_1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_1_connect(Net_314, dedicated_io_bus[0]);
	defparam cy_analog_virtualmux_1_connect.sig_width = 1;

    ZeroTerminal ZeroTerminal_13 (
        .z(Net_608));


    assign Net_610 = Net_608 | Net_611;

    cy_mxs40_csd_v1_0 CSD (
        .sense(Net_847),
        .rx(Net_13),
        .tx(Net_848),
        .shield(Net_273),
        .adc_channel(Net_324),
        .amuxa(Net_606),
        .amuxb(Net_846),
        .csh(Net_615),
        .cmod(Net_82),
        .shield_pad(Net_616),
        .dedicated_io(dedicated_io_bus[1:0]),
        .vref_ext(Net_34),
        .vref_pass(Net_850),
        .dsi_sense_in(Net_44),
        .dsi_sample_in(Net_1423),
        .dsi_start(Net_589),
        .dsi_count_val_sel(Net_851),
        .clock(Net_611),
        .dsi_sense_out(Net_813),
        .dsi_sample_out(Net_814),
        .dsi_csh_tank(Net_815),
        .dsi_cmod(Net_845),
        .dsi_hscmp(Net_817),
        .dsi_sampling(Net_818),
        .dsi_adc_on(Net_819),
        .dsi_count(Net_828[15:0]),
        .csd_tx(Net_821),
        .csd_tx_n(Net_822),
        .interrupt(Net_849));
    defparam CSD.adc_channel_count = 1;
    defparam CSD.dedicated_io_count = 2;
    defparam CSD.is_capsense = 1;
    defparam CSD.is_cmod_charge = 1;
    defparam CSD.rx_count = 1;
    defparam CSD.sense_as_shield = 0;
    defparam CSD.sensors_count = 1;
    defparam CSD.shield_as_sense = 0;
    defparam CSD.shield_count = 1;
    defparam CSD.tx_count = 1;


	cy_clock_v1_0
		#(.id("315c63aa-3ed5-4aed-96ad-b9fc4691d099/8273f0d6-caef-4cc7-ad3c-09656b78e2cb"),
		  .source_clock_id("2FB4EC85-8328-4C5A-9ED9-8B63060178EB"),
		  .divisor(255),
		  .period("0"),
		  .is_direct(0),
		  .is_digital(0))
		ModClk
		 (.clock_out(Net_611));


	wire [0:0] tmpFB_0__Sns_net;
	wire [0:0] tmpIO_0__Sns_net;
	electrical [0:0] tmpSIOVREF__Sns_net;

	cy_mxs40_gpio_v1_0
		#(.id("315c63aa-3ed5-4aed-96ad-b9fc4691d099/0113321b-4a37-46f6-8407-2f8646c68756"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("0"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases("Proximity0_Sns0"),
		  .pin_mode("A"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		Sns
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__Sns_net[0:0]}),
		  .analog({Net_847}),
		  .io({tmpIO_0__Sns_net[0:0]}),
		  .siovref(tmpSIOVREF__Sns_net));



	cy_mxs40_isr_v1_0
		#(.deepsleep_required(0),
		  .int_type(2'b10))
		ISR
		 (.int_signal(Net_849));


    cy_analog_noconnect_v1_0 cy_analog_noconnect_3 (
        .noconnect(Net_850));

    ZeroTerminal ZeroTerminal_9 (
        .z(Net_851));

	// cy_analog_virtualmux_2 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_2_connect(Net_866, Net_606);
	defparam cy_analog_virtualmux_2_connect.sig_width = 1;



endmodule

// top
module top ;

          wire  Net_1494;
    electrical  Net_133;
          wire  Net_1574;
          wire  Net_131;
          wire  Net_130;
          wire  Net_129;
          wire  Net_128;
          wire  Net_127;
          wire  Net_126;
          wire  Net_125;
          wire  Net_124;
          wire  Net_123;
          wire  Net_1573;
          wire  Net_121;
          wire  Net_120;
          wire  Net_119;
          wire  Net_118;
          wire  Net_117;
          wire  Net_115;
          wire  Net_114;
          wire  Net_113;
          wire  Net_112;
          wire  Net_111;
          wire  Net_110;
          wire  Net_1572;
          wire  Net_96;
          wire  Net_95;
          wire  Net_94;
          wire  Net_93;
          wire  Net_92;
          wire  Net_91;
          wire  Net_90;
          wire  Net_88;
          wire  Net_87;
          wire  Net_1571;
          wire  Net_85;
          wire  Net_84;
          wire  Net_83;
          wire  Net_82;
          wire  Net_81;
          wire  Net_80;
          wire  Net_79;
          wire  Net_78;
          wire  Net_77;
          wire  Net_76;
          wire  Net_75;
    electrical  Net_74;
          wire  Net_1570;
          wire  Net_1569;
          wire  Net_562;
          wire  Net_561;
          wire  Net_560;
          wire  Net_559;
          wire  Net_558;
          wire  Net_557;
          wire  Net_556;
          wire  Net_555;
          wire  Net_554;
          wire  Net_553;
          wire  Net_563;
          wire  Net_1568;
          wire  Net_51;
          wire  Net_50;
          wire  Net_49;
          wire  Net_48;
          wire  Net_173;
          wire  Net_47;
          wire  Net_46;
          wire  Net_45;
          wire  Net_44;
          wire  Net_43;
          wire  Net_439;
          wire  Net_438;
          wire  Net_437;
          wire  Net_436;
          wire  Net_435;
          wire  Net_434;
          wire  Net_433;
          wire  Net_432;
          wire  Net_431;
          wire  Net_430;
          wire  Net_32;
          wire  Net_1567;
          wire  Net_462;
          wire  Net_461;
          wire  Net_460;
          wire  Net_459;
          wire  Net_458;
          wire  Net_457;
          wire  Net_456;
          wire  Net_455;
          wire  Net_454;
          wire  Net_453;
          wire  Net_20;
          wire  Net_19;
          wire  Net_18;
          wire  Net_17;
          wire  Net_16;
          wire  Net_15;
          wire  Net_679;
          wire  Net_678;
          wire  Net_677;
          wire  Net_676;
          wire  Net_882;
          wire  Net_10;
          wire  Net_9;
          wire  Net_8;
          wire  Net_7;
          wire  Net_6;
          wire  Net_5;
          wire  Net_4;
          wire  Net_3;
          wire  Net_2;
          wire  Net_1;
          wire  Net_1227;
          wire  Net_1238;
          wire  Net_116;
          wire  Net_192;
          wire  Net_1225;
          wire  Net_33679;
          wire  Net_820;
    electrical  Net_35683;
    electrical  Net_35207;
    electrical  Net_35242;
    electrical  Net_35105;
          wire  Net_838;
          wire  Net_228;
          wire  Net_89;
    electrical  Net_35512;
    electrical  Net_35134;
    electrical  Net_35137;
    electrical  Net_35146;

    SCB_UART_PDL_v2_0_0 UART_DEBUG (
        .cts_in(1'b0),
        .tx_out(Net_2),
        .rts_out(Net_3),
        .interrupt(Net_4),
        .clock(1'b0),
        .rx_dma(Net_6),
        .tx_dma(Net_7),
        .rx_in(1'b0),
        .rx_tx_out(Net_9),
        .tx_en_out(Net_10));

	wire [0:0] tmpFB_0__Pin_Orange_net;
	wire [0:0] tmpIO_0__Pin_Orange_net;
	electrical [0:0] tmpSIOVREF__Pin_Orange_net;

	cy_mxs40_gpio_v1_0
		#(.id("a61270bc-07ec-447d-ac9e-34cfe85c30e9"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("2"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		Pin_Orange
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__Pin_Orange_net[0:0]}),
		  .io({tmpIO_0__Pin_Orange_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_Orange_net));


	wire [0:0] tmpFB_0__Pin_Red_net;
	wire [0:0] tmpIO_0__Pin_Red_net;
	electrical [0:0] tmpSIOVREF__Pin_Red_net;

	cy_mxs40_gpio_v1_0
		#(.id("40e17ea4-3992-4362-855b-fd1f95cbc1d3"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		Pin_Red
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__Pin_Red_net[0:0]}),
		  .io({tmpIO_0__Pin_Red_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_Red_net));


    MCWDT_PDL_v1_10_1 MCWDT (
        .interrupt(Net_882));


	cy_mxs40_isr_v1_0
		#(.deepsleep_required(1),
		  .int_type(2'b10))
		WatchDog_IRQ
		 (.int_signal(Net_882));


    SCB_I2C_PDL_v2_0_2 SensorBus (
        .clock(1'b0),
        .scl_b(Net_677),
        .sda_b(Net_678),
        .scl_trig(Net_679));

	wire [0:0] tmpFB_0__Press1_net;
	wire [0:0] tmpIO_0__Press1_net;
	electrical [0:0] tmpSIOVREF__Press1_net;

	cy_mxs40_gpio_v1_0
		#(.id("dcba3538-6799-4eea-aabc-595d63c735ad"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("2"),
		  .ibuf_enabled("1"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("2"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		Press1
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__Press1_net[0:0]}),
		  .io({tmpIO_0__Press1_net[0:0]}),
		  .siovref(tmpSIOVREF__Press1_net));



	cy_gsref_v1_0
		#(.guid("8C3B410E-0600-5ECF-95DD-0AF91BF8D8A7"))
		GlobalSignal1
		 (.sig_out(Net_15));



	cy_mxs40_isr_v1_0
		#(.deepsleep_required(1),
		  .int_type(2'b01))
		Press1_IRQ
		 (.int_signal(Net_15));


    BLE_PDL_v2_0_4 Bluetooth (
        .pa_tx_en(Net_16),
        .lna_rx_en(Net_17),
        .pa_lna_en(Net_18));


	cy_mxs40_isr_v1_0
		#(.deepsleep_required(0),
		  .int_type(2'b10))
		AppControl_IRQ
		 (.int_signal(Net_19));


	wire [0:0] tmpIO_0__tmp_net;
	electrical [0:0] tmpSIOVREF__tmp_net;

	cy_mxs40_gpio_v1_0
		#(.id("4cca878b-77b5-471d-8aeb-ad6925202455"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("0"),
		  .ibuf_enabled("1"),
		  .init_dr_st("0"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		tmp
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({Net_19}),
		  .io({tmpIO_0__tmp_net[0:0]}),
		  .siovref(tmpSIOVREF__tmp_net));


	wire [0:0] tmpFB_0__DB_3_net;
	wire [0:0] tmpIO_0__DB_3_net;
	electrical [0:0] tmpSIOVREF__DB_3_net;

	cy_mxs40_gpio_v1_0
		#(.id("0826f6f1-1393-4c71-9baf-7162ad7eade5"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("0"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		DB_3
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__DB_3_net[0:0]}),
		  .io({tmpIO_0__DB_3_net[0:0]}),
		  .siovref(tmpSIOVREF__DB_3_net));


	wire [0:0] tmpFB_0__DB_2_net;
	wire [0:0] tmpIO_0__DB_2_net;
	electrical [0:0] tmpSIOVREF__DB_2_net;

	cy_mxs40_gpio_v1_0
		#(.id("ac6bd5fd-e861-4189-9422-1dbfc63785fe"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("0"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		DB_2
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__DB_2_net[0:0]}),
		  .io({tmpIO_0__DB_2_net[0:0]}),
		  .siovref(tmpSIOVREF__DB_2_net));


	wire [0:0] tmpFB_0__DB_1_net;
	wire [0:0] tmpIO_0__DB_1_net;
	electrical [0:0] tmpSIOVREF__DB_1_net;

	cy_mxs40_gpio_v1_0
		#(.id("29fcb762-a87a-463b-9879-eff9f4116a07"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("0"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		DB_1
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__DB_1_net[0:0]}),
		  .io({tmpIO_0__DB_1_net[0:0]}),
		  .siovref(tmpSIOVREF__DB_1_net));


	wire [0:0] tmpFB_0__DB_0_net;
	wire [0:0] tmpIO_0__DB_0_net;
	electrical [0:0] tmpSIOVREF__DB_0_net;

	cy_mxs40_gpio_v1_0
		#(.id("474b4c18-98ae-44ab-bbb8-e87a4178144f"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("0"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		DB_0
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__DB_0_net[0:0]}),
		  .io({tmpIO_0__DB_0_net[0:0]}),
		  .siovref(tmpSIOVREF__DB_0_net));


	wire [0:0] tmpFB_0__Green_net;
	wire [0:0] tmpIO_0__Green_net;
	electrical [0:0] tmpSIOVREF__Green_net;

	cy_mxs40_gpio_v1_0
		#(.id("7a4de49e-b2b5-48e6-aa9b-9c023b3f7859"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("4"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("1"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		Green
		 (.oe({1'b1}),
		  .y({Net_20}),
		  .fb({tmpFB_0__Green_net[0:0]}),
		  .io({tmpIO_0__Green_net[0:0]}),
		  .siovref(tmpSIOVREF__Green_net));



    assign Net_20 = ~Net_192;

    TCPWM_PWM_PDL_v1_0_5 LightOutputC (
        .kill(1'b0),
        .reload(1'b0),
        .start(1'b0),
        .count(1'b1),
        .swap(1'b0),
        .interrupt(Net_458),
        .ovrflw(Net_459),
        .undrflw(Net_460),
        .compare(Net_461),
        .clock(Net_116),
        .pwm(Net_192),
        .pwm_n(Net_462));


	cy_clock_v1_0
		#(.id("acdd7786-73aa-4f78-88aa-d3a9ea9d7ec9"),
		  .source_clock_id("2FB4EC85-8328-4C5A-9ED9-8B63060178EB"),
		  .divisor(0),
		  .period("20833333.3333333"),
		  .is_direct(0),
		  .is_digital(0))
		Clock_G
		 (.clock_out(Net_116));



    assign Net_32 = ~Net_33679;

    TCPWM_PWM_PDL_v1_0_6 LightOutputA (
        .kill(1'b0),
        .reload(1'b0),
        .start(1'b0),
        .count(1'b1),
        .swap(1'b0),
        .interrupt(Net_435),
        .ovrflw(Net_436),
        .undrflw(Net_437),
        .compare(Net_438),
        .clock(Net_1225),
        .pwm(Net_33679),
        .pwm_n(Net_439));

    TCPWM_Counter_PDL_v1_0_7 LightTimer (
        .stop(1'b0),
        .reload(1'b0),
        .start(1'b0),
        .count(1'b1),
        .capture(1'b0),
        .interrupt(Net_173),
        .ovrflw(Net_48),
        .undrflw(Net_49),
        .compare(Net_50),
        .clock(Net_51));


	cy_clock_v1_0
		#(.id("f41b3157-34c3-4f39-bfde-7cc9c5399833"),
		  .source_clock_id("2FB4EC85-8328-4C5A-9ED9-8B63060178EB"),
		  .divisor(0),
		  .period("781250000000"),
		  .is_direct(0),
		  .is_digital(0))
		LT_CLK
		 (.clock_out(Net_51));



	cy_mxs40_isr_v1_0
		#(.deepsleep_required(0),
		  .int_type(2'b10))
		LightTimer_IRQ
		 (.int_signal(Net_173));


	wire [0:0] tmpFB_0__Red_net;
	wire [0:0] tmpIO_0__Red_net;
	electrical [0:0] tmpSIOVREF__Red_net;

	cy_mxs40_gpio_v1_0
		#(.id("a6daf096-2dc7-4f03-9401-ec13522e9369"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("4"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("1"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		Red
		 (.oe({1'b1}),
		  .y({Net_32}),
		  .fb({tmpFB_0__Red_net[0:0]}),
		  .io({tmpIO_0__Red_net[0:0]}),
		  .siovref(tmpSIOVREF__Red_net));



    assign Net_563 = ~Net_1227;

    TCPWM_PWM_PDL_v1_0_8 LightOutputB (
        .kill(1'b0),
        .reload(1'b0),
        .start(1'b0),
        .count(1'b1),
        .swap(1'b0),
        .interrupt(Net_558),
        .ovrflw(Net_559),
        .undrflw(Net_560),
        .compare(Net_561),
        .clock(Net_1238),
        .pwm(Net_1227),
        .pwm_n(Net_562));

	wire [0:0] tmpFB_0__Blue_net;
	wire [0:0] tmpIO_0__Blue_net;
	electrical [0:0] tmpSIOVREF__Blue_net;

	cy_mxs40_gpio_v1_0
		#(.id("4a8c5acb-8775-4f5c-a5f1-62612792c127"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("4"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("1"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		Blue
		 (.oe({1'b1}),
		  .y({Net_563}),
		  .fb({tmpFB_0__Blue_net[0:0]}),
		  .io({tmpIO_0__Blue_net[0:0]}),
		  .siovref(tmpSIOVREF__Blue_net));



	cy_clock_v1_0
		#(.id("4847ec22-561c-499f-8197-22b40c09d503"),
		  .source_clock_id("2FB4EC85-8328-4C5A-9ED9-8B63060178EB"),
		  .divisor(0),
		  .period("20833333.3333333"),
		  .is_direct(0),
		  .is_digital(0))
		Clock_R
		 (.clock_out(Net_1225));



	cy_clock_v1_0
		#(.id("670e3d5f-65dd-4808-8ad9-f42d96b788e5"),
		  .source_clock_id("2FB4EC85-8328-4C5A-9ED9-8B63060178EB"),
		  .divisor(0),
		  .period("20833333.3333333"),
		  .is_direct(0),
		  .is_digital(0))
		Clock_B
		 (.clock_out(Net_1238));


    cy_annotation_universal_v1_0 R_2 (
        .connect({
            Net_74,
            Net_35512
        })
    );
    defparam R_2.comp_name = "Resistor_v1_0";
    defparam R_2.port_names = "T1, T2";
    defparam R_2.width = 2;

    cy_annotation_universal_v1_0 R_1 (
        .connect({
            Net_35146,
            Net_74
        })
    );
    defparam R_1.comp_name = "Resistor_v1_0";
    defparam R_1.port_names = "T1, T2";
    defparam R_1.width = 2;

    cy_annotation_universal_v1_0 GND_3 (
        .connect({
            Net_35146
        })
    );
    defparam GND_3.comp_name = "Gnd_v1_0";
    defparam GND_3.port_names = "T1";
    defparam GND_3.width = 1;

    cy_annotation_universal_v1_0 Q_1 (
        .connect({
            Net_35134,
            Net_74,
            Net_35146
        })
    );
    defparam Q_1.comp_name = "NFET_En_v1_0";
    defparam Q_1.port_names = "D, G, S";
    defparam Q_1.width = 3;

    cy_annotation_universal_v1_0 M_1 (
        .connect({
            Net_35137,
            Net_35134
        })
    );
    defparam M_1.comp_name = "Motor_v1_0";
    defparam M_1.port_names = "T1, T2";
    defparam M_1.width = 2;

    cy_annotation_universal_v1_0 PWR_1 (
        .connect({
            Net_35137
        })
    );
    defparam PWR_1.comp_name = "Power_v1_0";
    defparam PWR_1.port_names = "T1";
    defparam PWR_1.width = 1;

    cy_annotation_universal_v1_0 D_1 (
        .connect({
            Net_35134,
            Net_35137
        })
    );
    defparam D_1.comp_name = "Diode_v1_0";
    defparam D_1.port_names = "A, K";
    defparam D_1.width = 2;

    cy_annotation_universal_v1_0 C_1 (
        .connect({
            Net_35146,
            Net_35137
        })
    );
    defparam C_1.comp_name = "Capacitor_v1_0";
    defparam C_1.port_names = "T1, T2";
    defparam C_1.width = 2;

	wire [0:0] tmpFB_0__Motor_net;
	wire [0:0] tmpIO_0__Motor_net;
	electrical [0:0] tmpSIOVREF__Motor_net;

	cy_mxs40_gpio_v1_0
		#(.id("2371ef07-f809-4043-941c-29830193b65b"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("1"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("1"),
		  .hotswap_needed("0"))
		Motor
		 (.oe({1'b1}),
		  .y({Net_89}),
		  .fb({tmpFB_0__Motor_net[0:0]}),
		  .io({tmpIO_0__Motor_net[0:0]}),
		  .siovref(tmpSIOVREF__Motor_net),
		  .annotation({Net_35512}));


    TCPWM_PWM_PDL_v1_0_9 MotorOutput (
        .kill(1'b0),
        .reload(1'b0),
        .start(1'b0),
        .count(1'b1),
        .swap(1'b0),
        .interrupt(Net_80),
        .ovrflw(Net_81),
        .undrflw(Net_82),
        .compare(Net_83),
        .clock(Net_84),
        .pwm(Net_89),
        .pwm_n(Net_85));


	cy_clock_v1_0
		#(.id("b70896ed-5251-455a-a183-fa3e9758398c"),
		  .source_clock_id("2FB4EC85-8328-4C5A-9ED9-8B63060178EB"),
		  .divisor(0),
		  .period("20833333.3333333"),
		  .is_direct(0),
		  .is_digital(0))
		Clock_M
		 (.clock_out(Net_84));


    TCPWM_Counter_PDL_v1_0_10 MotorTimer (
        .stop(1'b0),
        .reload(1'b0),
        .start(1'b0),
        .count(1'b1),
        .capture(1'b0),
        .interrupt(Net_228),
        .ovrflw(Net_93),
        .undrflw(Net_94),
        .compare(Net_95),
        .clock(Net_96));


	cy_clock_v1_0
		#(.id("3ee2ca96-3e12-4a8d-a6d6-10a23ba9a894"),
		  .source_clock_id("2FB4EC85-8328-4C5A-9ED9-8B63060178EB"),
		  .divisor(0),
		  .period("781250000000"),
		  .is_direct(0),
		  .is_digital(0))
		MT_CLK
		 (.clock_out(Net_96));



	cy_mxs40_isr_v1_0
		#(.deepsleep_required(0),
		  .int_type(2'b10))
		MotorTimer_IRQ
		 (.int_signal(Net_228));


	wire [0:0] tmpFB_0__Chime_net;
	wire [0:0] tmpIO_0__Chime_net;
	electrical [0:0] tmpSIOVREF__Chime_net;

	cy_mxs40_gpio_v1_0
		#(.id("276be5b3-81b9-4098-8d7d-bc055dc4a62e"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("1"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("1"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("1"),
		  .hotswap_needed("0"))
		Chime
		 (.oe({1'b1}),
		  .y({Net_820}),
		  .fb({tmpFB_0__Chime_net[0:0]}),
		  .io({tmpIO_0__Chime_net[0:0]}),
		  .siovref(tmpSIOVREF__Chime_net),
		  .annotation({Net_35683}));


    TCPWM_PWM_PDL_v1_0_11 ChimeOutput (
        .kill(1'b0),
        .reload(1'b0),
        .start(1'b0),
        .count(1'b1),
        .swap(1'b0),
        .interrupt(Net_115),
        .ovrflw(Net_117),
        .undrflw(Net_118),
        .compare(Net_119),
        .clock(Net_120),
        .pwm(Net_820),
        .pwm_n(Net_121));


	cy_clock_v1_0
		#(.id("08256c57-487b-49ee-bbdc-8ff4e9eb6ac1"),
		  .source_clock_id("2FB4EC85-8328-4C5A-9ED9-8B63060178EB"),
		  .divisor(0),
		  .period("1000000000"),
		  .is_direct(0),
		  .is_digital(0))
		CO_CLK
		 (.clock_out(Net_120));


    TCPWM_Counter_PDL_v1_0_12 ChimeTimer (
        .stop(1'b0),
        .reload(1'b0),
        .start(1'b0),
        .count(1'b1),
        .capture(1'b0),
        .interrupt(Net_838),
        .ovrflw(Net_128),
        .undrflw(Net_129),
        .compare(Net_130),
        .clock(Net_131));


	cy_clock_v1_0
		#(.id("afd57b1e-c9ca-465d-ba2a-646d89c2b1b2"),
		  .source_clock_id("2FB4EC85-8328-4C5A-9ED9-8B63060178EB"),
		  .divisor(0),
		  .period("781250000000"),
		  .is_direct(0),
		  .is_digital(0))
		CT_CLK
		 (.clock_out(Net_131));



	cy_mxs40_isr_v1_0
		#(.deepsleep_required(0),
		  .int_type(2'b10))
		ChimeTimer_IRQ
		 (.int_signal(Net_838));


    cy_annotation_universal_v1_0 SPK_1 (
        .connect({
            Net_35242,
            Net_35105
        })
    );
    defparam SPK_1.comp_name = "Speaker_v1_0";
    defparam SPK_1.port_names = "T1, T2";
    defparam SPK_1.width = 2;

    cy_annotation_universal_v1_0 R_3 (
        .connect({
            Net_35207,
            Net_133
        })
    );
    defparam R_3.comp_name = "Resistor_v1_0";
    defparam R_3.port_names = "T1, T2";
    defparam R_3.width = 2;

    cy_annotation_universal_v1_0 GND_1 (
        .connect({
            Net_35207
        })
    );
    defparam GND_1.comp_name = "Gnd_v1_0";
    defparam GND_1.port_names = "T1";
    defparam GND_1.width = 1;

    cy_annotation_universal_v1_0 PWR_2 (
        .connect({
            Net_35105
        })
    );
    defparam PWR_2.comp_name = "Power_v1_0";
    defparam PWR_2.port_names = "T1";
    defparam PWR_2.width = 1;

    cy_annotation_universal_v1_0 Q_2 (
        .connect({
            Net_35242,
            Net_133,
            Net_35207
        })
    );
    defparam Q_2.comp_name = "NFET_En_v1_0";
    defparam Q_2.port_names = "D, G, S";
    defparam Q_2.width = 3;

    cy_annotation_universal_v1_0 R_5 (
        .connect({
            Net_35105,
            Net_35242
        })
    );
    defparam R_5.comp_name = "Resistor_v1_0";
    defparam R_5.port_names = "T1, T2";
    defparam R_5.width = 2;

    cy_annotation_universal_v1_0 R_4 (
        .connect({
            Net_133,
            Net_35683
        })
    );
    defparam R_4.comp_name = "Resistor_v1_0";
    defparam R_4.port_names = "T1, T2";
    defparam R_4.width = 2;


	cy_mxs40_isr_v1_0
		#(.deepsleep_required(0),
		  .int_type(2'b10))
		Shake_IRQ
		 (.int_signal(1'b1));


    RTC_PDL_v2_0_13 RealTimeClock ();

	wire [0:0] tmpFB_0__Pin_Shake_net;
	wire [0:0] tmpIO_0__Pin_Shake_net;
	electrical [0:0] tmpSIOVREF__Pin_Shake_net;

	cy_mxs40_gpio_v1_0
		#(.id("d30caab5-2fe7-4bc3-86c2-db4d5f9c5a57"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("3"),
		  .ibuf_enabled("1"),
		  .init_dr_st("0"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		Pin_Shake
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__Pin_Shake_net[0:0]}),
		  .io({tmpIO_0__Pin_Shake_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_Shake_net));


    CapSense_v2_0_14 CapSense ();



endmodule

