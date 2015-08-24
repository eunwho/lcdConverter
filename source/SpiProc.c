/////////////////////////////////////////////////////////////////////////
//	Project Name 	: Input for EW Inverter  
//	Fiele Name	 	: SpiProc.c
//
//  Start 			: 2007.06.03 sunday
//
///////////////////////////////////////////////////////////////////////////


// Error�� �߻��ϸ� ErrCode�� return �Ѵ�.
// str�� ������ string ������ ���� null�� �ѿ��� ���� ��   
#SEPARATE
int iSpiSend(char *str)
{
	int ErrCode;
	
	int Loop;
	long lStartMsec, lTemp;
		
	gSpiRxFlag = FALSE;	 
	
	
	ErrCode=0;
	
	lStartMsec = lGetMsec();

	// wait for finishing last command string
	while(Loop){
		if (gSpiRxFlag == TRUE) Loop = FALSE;		

		lTemp = lGetDelayMsec(lStartMsec);

		if ( lTemp > 100) Loop = False;

	}
	
	// if not error Send Spi Command String
	
	if( gSpiRxFlag ) 	 
	{
		strcopy(gSpiTxBuf,Str);		
		gSpiRxFlag = FALSE;	
		
		lStartMsec = lGetMsec();
	
		while(Loop){
			if (gSpiRxFlag == TRUE) Loop = FALSE;		
			if ( lGetDelayMSec( lStartMsec) > 100) Loop = False;
		}
	}
	if(gSpiRxFlag == FALSE ) {
		strcpy(str,"- Off Line -");
		ErrCode = ERR_SPI_CONNECT;
	}
	else{ 
		strcopy(str,gSpiRxBuf);	
		if(str[0] == 'E') ErrCode = 1;
	}
	return ErrCode;
}
