#include <stdio.h>
#include <stdlib.h>
#include "DriverJeuLaser.h"
#include "ServiceJeuLaser.h"

extern void GestionSon_callback(void);

int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

/* Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers */
	CLOCK_Configure();

/* Configuration du son (voir ServiceJeuLaser.h) 
 Insérez votre code d'initialisation des parties matérielles gérant le son ....*/	


	ServJeuLASER_Son_Init(1000,(char)0,GestionSon_callback); 
	

//============================================================================	
	
	
	while	(1)
	{
		
	}
}




