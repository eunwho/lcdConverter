#ifndef		__GLOBAL_VAR_
#define		__GLOBAL_VAR_

int machine_state;
unsigned long secWatchDog;
//int machine_stae;
int CodeID;
int Code[12]={0};

char gSciTxBuf[16];
char st[21]={0};
unsigned long gulRtsCount;				// Incr Timer2 irq base Clockof system

int lcd_x_posi=0;
int lcd_y_posi=1;
int disp_count=0;

int sci_rx_msg_start=0;
int sci_rx_msg_end=0;
char sci_rx_msg_box[SCI_RX_MSG_SIZE]={0};
char Trip_Message[21] = {0};

char Flag_Btn = 1;		// Trip Page Flag
char Flag_Set = 1;		// Select Control Flag for Set button
char Flag_Start = 0;	// Text Output Toggle Flag
char Flag_Page = 1;		// Menu Page
char Flag_Time = 0;		// 
char Trip_Header[]="trp";
char Trip_Error = 0;
char Error_y_posi = 0;
char Error_x_posi = 0;
char Time_Count = 2;
signed char Time_Set_Number = 0;
//char Header_Count = 0;
#endif