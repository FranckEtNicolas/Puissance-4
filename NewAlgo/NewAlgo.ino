int columns[7] = {0,0,0,0,0,0,0};
int prio[7] = {0,0,0,0,0,0,0};
int histoJ[42][2] ={};              // On rajoute dans l'histo {colonne, ligne} de chaque jeton
int histoC[42][2] ={};              // Idem
int nbMoves = 0;

bool elementInArray(int pos[2], int array[42][2]){
  for(int i = 0; i < 42; i++){
    if (array[i][0] == pos[0] && array[i][1] == pos[1]){
      return true;
    }
  }
  return false;
}

void play(int column) {
  columns[column] += 1;
  histoC[getNbMoves()][0] = column;
  histoC[getNbMoves()][1] = columns[column];
  nbMoves += 1;
}

void playJ(int column){
  columns[column -1] += 1;
  histoJ[getNbMoves()][0] = column - 1;
  histoJ[getNbMoves()][1] = columns[column - 1];
  nbMoves += 1;
}

int getNbMoves(){
  return nbMoves;
}

bool canPlay(int column){
  if (columns[column] < 6){
    return true;
  }
  return false;
}

bool checkLine4(int pos[2], int histo[42][2]){
  int x = pos[0];        //Colonne
  int y = pos[1];        //Ligne
  int pos_a[2] = {x+1,y};
  int pos_b[2] = {x+2,y};
  int pos_c[2] = {x+3,y};
  int pos_e[2] = {x-1,y};
  int pos_f[2] = {x-2,y};
  int pos_g[2] = {x-3,y};

  if (elementInArray(pos_a, histo) && elementInArray(pos_b, histo) && elementInArray(pos_c, histo)){
    return true;
  }
  else if (elementInArray(pos_e, histo) && elementInArray(pos_f, histo) && elementInArray(pos_g, histo)){
    return true;
  }
  else if (elementInArray(pos_a, histo) && elementInArray(pos_e, histo) && elementInArray(pos_f, histo)){
    return true;
  }
  else if (elementInArray(pos_a, histo) && elementInArray(pos_b, histo) && elementInArray(pos_e, histo)){
    return true;
  }
  return false;
}

bool checkColumn4(int pos[2], int histo[42][2]){
  int x = pos[0];        //Colonne
  int y = pos[1];        //Ligne
  int pos_e[2] = {x,y-1};
  int pos_f[2] = {x,y-2};
  int pos_g[2] = {x,y-3};

  if (elementInArray(pos_e, histo) && elementInArray(pos_f, histo) && elementInArray(pos_g, histo)){
    return true;
  }
  return false;
}

bool checkDiago4(int pos[2], int histo[42][2]){
  int x = pos[0];        //Colonne
  int y = pos[1];        //Ligne
  int pos_a[2] = {x+1,y-1};
  int pos_b[2] = {x+2,y-2};
  int pos_c[2] = {x+3,y-3};
  int pos_e[2] = {x+1,y+1};
  int pos_f[2] = {x+2,y+2};
  int pos_g[2] = {x+3,y+3};

  int pos_a2[2] = {x-1,y-1};
  int pos_b2[2] = {x-2,y-2};
  int pos_c2[2] = {x-3,y-3};
  int pos_e2[2] = {x-1,y+1};
  int pos_f2[2] = {x-2,y+2};
  int pos_g2[2] = {x-3,y+3};

  if (elementInArray(pos_a, histo) && elementInArray(pos_b, histo) && elementInArray(pos_c, histo)){
    return true;
  }
  else if (elementInArray(pos_a, histo) && elementInArray(pos_b, histo) && elementInArray(pos_e2, histo)){
    return true;
  }
  else if (elementInArray(pos_a, histo) && elementInArray(pos_e2, histo) && elementInArray(pos_f2, histo)){
    return true;
  }
  else if (elementInArray(pos_e2, histo) && elementInArray(pos_f2, histo) && elementInArray(pos_g2, histo)){
    return true;
  }

  else if (elementInArray(pos_e, histo) && elementInArray(pos_f, histo) && elementInArray(pos_g, histo)){
    return true;
  }
  else if (elementInArray(pos_a2, histo) && elementInArray(pos_e, histo) && elementInArray(pos_f, histo)){
    return true;
  }
  else if (elementInArray(pos_b2, histo) && elementInArray(pos_a2, histo) && elementInArray(pos_e, histo)){
    return true;
  }
  else if (elementInArray(pos_c2, histo) && elementInArray(pos_b2, histo) && elementInArray(pos_a2, histo)){
    return true;
  }
  
  return false;
}

bool checkLine3(int pos[2], int histo[42][2]){
  int x = pos[0];        //Colonne
  int y = pos[1];        //Ligne
  int pos_a[2] = {x+1,y};
  int pos_b[2] = {x+2,y};
  int pos_e[2] = {x-1,y};
  int pos_f[2] = {x-2,y};

  if (elementInArray(pos_a, histo) && elementInArray(pos_b, histo)) {
    return true;
  }
  else if (elementInArray(pos_e, histo) && elementInArray(pos_f, histo)){
    return true;
  }
  else if (elementInArray(pos_a, histo) && elementInArray(pos_e, histo)){
    return true;
  }
  return false;
}

bool checkColumn3(int pos[2], int histo[42][2]){
  int x = pos[0];        //Colonne
  int y = pos[1];        //Ligne
  int pos_e[2] = {x,y-1};
  int pos_f[2] = {x,y-2};

  if (elementInArray(pos_e, histo) && elementInArray(pos_f, histo) && y != 6){
    return true;
  }
  return false ;
}

bool checkDiago3(int pos[2], int histo[42][2]){
  int x = pos[0];        //Colonne
  int y = pos[1];        //Ligne
  int pos_a[2] = {x+1,y-1};
  int pos_b[2] = {x+2,y-2};
  int pos_e[2] = {x+1,y+1};
  int pos_f[2] = {x+2,y+2};

  int pos_a2[2] = {x-1,y-1};
  int pos_b2[2] = {x-2,y-2};
  int pos_e2[2] = {x-1,y+1};
  int pos_f2[2] = {x-2,y+2};

  if (elementInArray(pos_a, histo) && elementInArray(pos_b, histo) && y <= 5 && x >= 1){
    return true;
  }
  else if (elementInArray(pos_a, histo) && elementInArray(pos_e2, histo)){
    return true;
  }
  else if (elementInArray(pos_e2, histo) && elementInArray(pos_f2, histo) && x >= 2 && y <= 5){
    return true;
  }

  else if (elementInArray(pos_e, histo) && elementInArray(pos_f, histo) && x <= 4 && y <= 5){
    return true;
  }
  else if (elementInArray(pos_a2, histo) && elementInArray(pos_e, histo) && y <= 5 && x <= 5){
    return true;
  }
  else if (elementInArray(pos_a2, histo) && elementInArray(pos_b2, histo)){
    return true;
  }
  return false;
}

bool checkLine2(int pos[2], int histo[42][2]){
  int x = pos[0];        //Colonne
  int y = pos[1];        //Ligne
  int pos_a[2] = {x+1,y};
  int pos_e[2] = {x-1,y};

  if (elementInArray(pos_a, histo)){
    return true;
  }
  else if (elementInArray(pos_e, histo)){
    return true;
  }
  return false;
}

bool checkColumn2(int pos[2], int histo[42][2]){
  int x = pos[0];        //Colonne
  int y = pos[1];        //Ligne
  int pos_a[2] = {x,y+1};
  int pos_e[2] = {x,y-1};

  if (elementInArray(pos_a, histo)){
    return true;
  }
  else if (elementInArray(pos_e, histo) && y <= 5){
    return true;
  }
  return false ;
}

bool checkDiago2(int pos[2], int histo[42][2]){
  int x = pos[0];        //Colonne
  int y = pos[1];        //Ligne
  int pos_a[2] = {x+1,y-1};
  int pos_e[2] = {x+1,y+1};

  int pos_a2[2] = {x-1,y-1};
  int pos_e2[2] = {x-1,y+1};

  if (elementInArray(pos_a, histo) && y <= 4 && x <= 5){
    return true;
  }
  else if (elementInArray(pos_e, histo) && x <= 5 && y <= 4){
    return true;
  }

  else if (elementInArray(pos_a2, histo) && y <= 4 && x >= 3){
    return true;
  }
  else if (elementInArray(pos_e2, histo) && x >= 3 && y <= 4){
    return true;
  }

  return false ;
}

bool checkWin(int pos[2], int histo[42][2]){
  if (checkLine4(pos, histo) == true || checkColumn4(pos, histo) == true || checkColumn4(pos, histo) == true){
    return true;
  }
  return false;
}

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 42; i++){
    histoJ[i][0] = -2;
    histoJ[i][1] = -2;
    histoC[i][0] = -2;
    histoC[i][1] = -2;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int prio[7] = {0,0,0,0,0,0,0};
  int prioSet[7] = {0,0,0,0,0,0,0};
  for (int i = 0; i < 7; i++){

    if (canPlay(i) == true){
      columns[i] += 1;
      int posTempo[2] = {i, columns[i]};
      Serial.println(posTempo[0]);
      Serial.println(posTempo[1]);
      histoC[getNbMoves()][0] = posTempo[0];
      histoC[getNbMoves()][1] = posTempo[1];
      
      if (checkWin(posTempo, histoC) == true && prioSet[i] == 0){       //Si l'ordi peut gagner en jouant dans cette colonne, prio absolue
        prio[i] = 100;
        prioSet[i] = 1;
      }

      else if (checkLine4(posTempo, histoJ) == true || checkColumn4(posTempo, histoJ) || checkDiago4(posTempo, histoJ)){ //Si l'ordi peut bloquer une victoire adverse
        if (prioSet[i] == 0){
          prio[i] = 99; 
          prioSet[i] = 1;
        }
      }

      else if (checkLine3(posTempo, histoC) == true || checkColumn3(posTempo, histoC) == true || checkDiago3(posTempo, histoC)){ //Si l'ordi peut aligner trois jetons
        if (prioSet[i] == 0){
          prio[i] = 10; 
          if (columns[i] < 6){
            int posTempo2[2] = {i, columns[i] + 1};
            if (checkLine4(posTempo2, histoJ) == true || checkColumn4(posTempo2, histoJ) || checkDiago4(posTempo2, histoJ)){    //...mais que cela permet au joueur de gagner
              prio[i] -= 100;     //prio = -90
            }
            else if (checkLine3(posTempo2, histoJ) == true || checkColumn3(posTempo2, histoJ) || checkDiago3(posTempo2, histoJ)){ //ou d'aligner 3 jetons
              prio[i] -= 1;      //prio = 9
            }
            else if (checkLine2(posTempo2, histoJ) == true || checkColumn2(posTempo2, histoJ) == true || checkDiago2(posTempo2, histoJ)){ //ou d'aligner 2 jetons
              prio[i] -= 2;      //prio = 8
            }
          }
          prioSet[i] = 1;
        }
      }

      else if (checkLine2(posTempo, histoJ) == true || checkColumn2(posTempo, histoJ) == true || checkDiago2(posTempo, histoJ)){ //Si l'ordi peut bloquer un alignement de 2 jetons adverses
        if (prioSet[i] == 0){
          prio[i] = 5;
          prioSet[i] = 1;
        }
      }

      else if (checkLine2(posTempo, histoC) == true || checkColumn2(posTempo, histoC) == true || checkDiago2(posTempo, histoC)){  //Si l'ordi peut aligner deux jetons
        if (prioSet[i] == 0){
          prio[i] = 3;
          if(columns[i] < 6){
            int posTempo2[2] = {i, columns[i] + 1};
            if (checkLine4(posTempo2, histoJ) == true || checkColumn4(posTempo2, histoJ) || checkDiago4(posTempo2, histoJ)){    //...mais que cela permet au joueur de gagner
              prio[i] -= 100;    //prio = -97
            }
            else if (checkLine3(posTempo2, histoJ) == true || checkColumn3(posTempo2, histoJ) || checkDiago3(posTempo2, histoJ)){ //ou d'aligner 3 jetons
              prio[i] -= 1;     //prio = 4
            }
            else if (checkLine2(posTempo2, histoJ) == true || checkColumn2(posTempo2, histoJ) == true || checkDiago2(posTempo2, histoJ)){ //ou d'aligner 2 jetons
              prio[i] -= 2;     //prio = 3
            }
          }
          prioSet[i] = 1;
        }
      }
      columns[i] -= 1;
      histoC[getNbMoves()][0] = -1;
      histoC[getNbMoves()][1] = -1;
      
    }

    else{
      prio[i] = 0;
    }
  }
  
  int prioFin = -999;
  int columnFin = -1;

  for (int i = 0; i < 7; i++){
    Serial.print("Prio : ");
    Serial.print(prio[i]);
    Serial.print(" ");
    Serial.println(prioSet[i]);
  }

  for (int i = 0; i < 7; i++){
    if (prio[i] > prioFin){
      prioFin = prio[i];
      columnFin = i;
    }
  }

  if (prio[0] == prio[1] && prio[1] == prio[2] && prio[2] == prio[3] && prio[3] == prio[4] && prio[4] == prio[5] && prio[5] == prio[6]){
    columnFin = 3;
  }
  
  play(columnFin);
  Serial.print("L'ordi a joué en colonne ");
  Serial.println(columnFin + 1);
                                                     //Fin tour ordi
  for (int i = 0; i < 7; i++){
    Serial.println(columns[i]);
  }
  
  Serial.println("Où voulez-vous jouer?");

  while (Serial.available() == 0){                    //On attend que le joueur joue
  }

  int columnJ = Serial.parseInt();
  Serial.println("Vous avez joué dans la colonne" + columnJ);
  playJ(columnJ);

}

