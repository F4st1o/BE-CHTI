; Acc�s au fonctions de services de ServiceLaser.c avec une appelant ASM



;/**
;	* @brief  Configure tous les �l�ments mat�riels (p�riph�riques) qui g�rent le son 
;						Une fois la fonction ex�cut�e, les p�riph�riques ci-dessous sont lanc�s, l'interruption
;						qui appelle p�riodiquement le callback est valid�e.
;  * @note   Periph�riques utilis�s :
;						- TIM4 : il provoque l'appel du callback � intervalle de tps r�gulier, Te (Periode_Te_us)
;						- TIM3 : il g�n�re le signal PWM de fr�quence 100kHz. La valeur num�rique "� convertir
;						en analogique" est pass�e par la fonction d�di�e accessible via le header DriverJeuLaser.h
;						(void PWM_Set_Value_TIM3_Ch3( unsigned short int Thaut_ticks)).
;						- La pin par laquelle sort le signal PWM est PB.0 (configur� en alt PushPull).
;						
;		* @param  int Periode_Te_us : intervalle de temps donn� en �s entre deux appels cons�cutifs du callback
;							prio : niveau de priorit� de l'interruption qui lance le callback. 
;											0 = priorit� maxi
;										 15 = priorit� mini
;							IT_function : nom de la fonction qui est appel�e � �ch�ance du compteur TIM4, cad
;														toutes les Periode_Te_us �s.
;	
;  * @retval None
;  */
;void ServJeuLASER_Son_Init(int Periode_Te_us, char prio, void (*IT_function)(void));

	import ServJeuLASER_Son_Init


;/**
;	* @brief  Convertit un entier en une valeur "analogique" proportionnelle. 
;						Le convertisseur est une PWM (non un DAC). La fr�quence de PWM est suppos�e r�gl�e � 100kHz. 
;						La plage de valeurs possibles en entr�e s'�tend de 0 � 719 correspondant proportionnellement 
;						� un rapport cyclique de 0 � 100%
;						
;  * @note   ATTENTION ! L'utilisation de cette fonction suppose que l'initialisation a d�j� �t� ex�cut�e
;						(cf . fonction ServJeuLASER_Son_Init
;						
;	* @param  EchSon : valeur � convertir "en analogique"
;	
;  * @retval None
;  */
;void ServJeuLASER_WritePWMSoundVal(unsigned short int EchSon);

	import ServJeuLASER_WritePWMSoundVal

	end
