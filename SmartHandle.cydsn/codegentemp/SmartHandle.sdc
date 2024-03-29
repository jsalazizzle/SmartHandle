# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\salaz\Desktop\SmartHandle\SmartHandle.cydsn\SmartHandle.cyprj
# Date: Thu, 21 Mar 2019 00:28:31 GMT
#set_units -time ns
create_clock -name {CyClk_LF} -period 30517.578125 -waveform {0 15258.7890625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyFLL} -period 20 -waveform {0 10} [list [get_pins {ClockBlock/fll}]]
create_clock -name {CyClk_HF0} -period 20 -waveform {0 10} [list [get_pins {ClockBlock/hfclk_0}]]
create_clock -name {CyClk_Fast} -period 20 -waveform {0 10} [list [get_pins {ClockBlock/fastclk}]]
create_clock -name {CyClk_Peri} -period 40 -waveform {0 20} [list [get_pins {ClockBlock/periclk}]]
create_generated_clock -name {CyClk_Slow} -source [get_pins {ClockBlock/periclk}] -edges {1 2 3} [list [get_pins {ClockBlock/slowclk}]]
create_generated_clock -name {Clock_G} -source [get_pins {ClockBlock/periclk}] -edges {1 2 3} [list [get_pins {ClockBlock/ff_div_11}]]
create_generated_clock -name {Clock_R} -source [get_pins {ClockBlock/periclk}] -edges {1 2 3} [list [get_pins {ClockBlock/ff_div_12}]]
create_generated_clock -name {Clock_B} -source [get_pins {ClockBlock/periclk}] -edges {1 2 3} [list [get_pins {ClockBlock/ff_div_13}]]
create_generated_clock -name {LT_CLK} -source [get_pins {ClockBlock/periclk}] -edges {1 19531 39063} [list [get_pins {ClockBlock/ff_div_14}]]
create_generated_clock -name {Clock_M} -source [get_pins {ClockBlock/periclk}] -edges {1 2 3} [list [get_pins {ClockBlock/ff_div_15}]]
create_generated_clock -name {CT_CLK} -source [get_pins {ClockBlock/periclk}] -edges {1 19531 39063} [list [get_pins {ClockBlock/ff_div_16}]]
create_generated_clock -name {MT_CLK} -source [get_pins {ClockBlock/periclk}] -edges {1 19531 39063} [list [get_pins {ClockBlock/ff_div_17}]]
create_generated_clock -name {UART_DEBUG_SCBCLK} -source [get_pins {ClockBlock/periclk}] -edges {1 19 37} [list [get_pins {ClockBlock/ff_div_5}]]
create_generated_clock -name {SensorBus_SCBCLK} -source [get_pins {ClockBlock/periclk}] -edges {1 17 33} [list [get_pins {ClockBlock/ff_div_6}]]
create_generated_clock -name {CO_CLK} -source [get_pins {ClockBlock/periclk}] -edges {1 25 51} [list [get_pins {ClockBlock/ff_div_21}]]
create_clock -name {CyPeriClk_App} -period 40 -waveform {0 20} [list [get_pins {ClockBlock/periclk_App}]]
create_clock -name {CyIMO} -period 125 -waveform {0 62.5} [list [get_pins {ClockBlock/imo}]]


# Component constraints for C:\Users\salaz\Desktop\SmartHandle\SmartHandle.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\salaz\Desktop\SmartHandle\SmartHandle.cydsn\SmartHandle.cyprj
# Date: Thu, 21 Mar 2019 00:28:11 GMT
