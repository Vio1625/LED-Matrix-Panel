#include <DFRobot_RGBMatrix.h> // Hardware-specific library
#include <Wire.h>
#define OE    9
#define LAT   10
#define CLK   11
#define A     A0
#define B     A1
#define C     A2
#define D     A3
#define E     A4
#define WIDTH 64       // taille en largeur (panneau 64x64)
#define HIGH  64      // taille en hauteur
int a = 8;
int b = 24;

DFRobot_RGBMatrix matrix(A, B, C, D, E, CLK, LAT, OE, false, WIDTH, HIGH);

// matrix.Color333(x,y,z): x:rouge   y:bleu  z:vert

void setup()
{
  matrix.begin();
}

void AffichageNbrPlaces(int nbr_places)
{

  if (nbr_places > 29) // le parking est fermé
  
  {
    matrix.drawRect(0, 0, WIDTH ,HIGH, matrix.Color333(7, 0, 0));  // cadre dans lequel on va écrire "Parking complet"
    matrix.drawRect(1, 1, 62, 62, matrix.Color333(7, 0, 0)); 
    matrix.drawRect(2, 2, 60, 60, matrix.Color333(7, 0, 0)); 
    matrix.drawRect(3, 3, 58, 58, matrix.Color333(7, 0, 0)); 
    matrix.setTextWrap(false);
    matrix.setTextSize(1);         // définie la taille d'une lettre à 8 pixels de haut
    matrix.setCursor(12, 16);      // le curseur se situe à au douzième pixel en longueur et à la troisième ligne du panneau (avec un texte de taille 1)
    uint8_t w = 0;
    char *str = "Parkingcomplet";
    for (w = 0; w < 7; w++) {
      matrix.setTextColor(matrix.Color333(0, 7, 7)); // on définit la couleur du texte
      matrix.print(str[w]);
    }

    matrix.setCursor(12, 32);     // le curseur se situe à au quinzième pixel en longueur et à la quatrième ligne du panneau (avec un texte de taille 1)
    for (w = 7; w < 14; w++) {
      matrix.setTextColor(matrix.Color333(0, 7, 7));
      matrix.print(str[w]);
    }
  }




    else                // le parking est ouvert
    {
      int nbr_places_disp=30-nbr_places;
      matrix.drawRect(0, 0, WIDTH, HIGH, matrix.Color333(7, 0, 0));  // cadre dans lequel on va écrire "Parking ouvert"
      matrix.setTextWrap(false);
      matrix.setTextSize(1);         // définie la taille d'une lettre à 8 pixels de haut
      matrix.setCursor(12, 16);      // le curseur se situe à au douzième pixel en longueur et à la troisième ligne du panneau (avec un texte de taille 1)
      uint8_t w = 0;
      char *str = "Parkingouvert";
      for (w = 0; w < 7; w++) {
        matrix.setTextColor(matrix.Color333(0, 0, 7)); // on définit la couleur du texte
        matrix.print(str[w]);
      }

      matrix.setCursor(15, 32);     // le curseur se situe à au quinzième pixel en longueur et à la quatrième ligne du panneau (avec un texte de taille 1)
      for (w = 7; w < 13; w++) {
        matrix.setTextColor(matrix.Color333(0, 0, 7));
        matrix.print(str[w]);
      }

      delay(1500);

      uint8_t i = 0;
      matrix.setTextSize(2);        // on définit la taille du texte à 2 soit 16 pixels de haut et 11 pixels de large
      while (i < 185)
      {
        for (a = 8; a > -370; a = a - 2)
        {
          matrix.fillScreen(matrix.Color333(0, 0, 0)); // on met l'écran en noir pour réinitialiser
          matrix.setCursor(a, b);
          
          matrix.print("Il reste "+String(nbr_places_disp)+" places disponibles");  // 30 caractères
          delay(15);
          i++;
        }
      }
    }
  }

  void loop()
  {
    int nbr_places=2;
    AffichageNbrPlaces(nbr_places);
    
  }
