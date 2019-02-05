#ifndef __CONFIG__
#define __CONFIG__


/* HARDWARE PIN */
#define PROX_TRIG_PIN 7
#define PROX_ECHO_PIN 8
#define BLUETOOTH_RX_PIN 0
#define BLUETOOTH_TX_PIN 1


/* servo motor */
#define SERVO_PIN 9

/* modality led */
#define L1_PIN 11
#define L2_PIN 12
#define LM_PIN 13

/* SOFTWARE COSTANT */

/* minimum value of humidity */
#define U_MIN 0.3

/* delta for humidity  */
#define DELTA_U 0.05

/* max time of erogation */
#define T_MAX 5000


// SARANNO DA METTERE I GIUSTI VALORI PER MUOVERE IL MOTORE SERVO_PIN

/* minimum flow of pump*/
#define P_MIN 1

/* medium flow of pump*/
#define P_MED 2

/* maximum flow of pump*/
#define P_MAX 
3

#endif