// La liaison série
#define rxPin 0
#define txPin 1

// les constantes du cube
#define DECODER_BITS 8
#define LEDS_PER_ROW 8

//pins connectées aux décodeurs controllant les colonnes d'anodes
#define p0 5 //Sur les décodeurs clients, pin A0
#define p1 4 //Sur les décodeurs clients, pin A1
#define p2 3 //Sur les décodeurs clients, pin A2

//pins connectées au décodeur (M) controllant l'activation des décodeurs clients
#define m0 6 //Choix du décodeur à activer par l'intermediaire du décodeur principal (M)
#define m1 7 //Choix du décodeur à activer par l'intermediaire du décodeur principal (M)
#define m2 10 //Choix du décodeur à activer par l'intermediaire du décodeur principal (M)

// pins connectées aux transistors controllant les cathodes (les couches de LED)
#define Z0 13
#define Z1 12
#define Z2 11

/*
 * Enregistrement du nombre de pins allant aux différents decodeurs dans des tableaux pour
   une saisie plus facile des LED à controler
 */
PROGMEM prog_int16_t anodeDecoderPins[] = {p0, p1, p2};
PROGMEM prog_int16_t masterDecoderPins[] = {m0, m1, m2};
PROGMEM prog_int16_t cathodeDecoderPins[] = {Z0, Z1, Z2};
