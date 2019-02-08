#ifndef __CONFIG__
#define __CONFIG__

/* HARDWARE PIN */
#define PROX_TRIG_PIN 7
#define PROX_ECHO_PIN 8
#define BLUETOOTH_RX_PIN 0
#define BLUETOOTH_TX_PIN 1

/* servo motor */
#define SERVO_PIN 11

/* modality led */
#define L1_PIN 12
#define L2_PIN 5
#define LM_PIN 13

/* SOFTWARE COSTANT */

/* distance for manual control */
#define DIST 0.3

/* minimum value of humidity */
#define U_MIN 30

/* delta for humidity  */
#define DELTA_U 5

/* max time of erogation */
#define T_MAX 5000

// SARANNO DA METTERE I GIUSTI VALORI PER MUOVERE IL MOTORE SERVO_PIN

/* closed pump*/
#define P_CLOSE 30

/* minimum flow of pump*/
#define P_MIN 80

/* medium flow of pump*/
#define P_MED 130

/* maximum flow of pump*/
#define P_MAX 180

#endif
