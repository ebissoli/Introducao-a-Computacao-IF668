#include <Arduino.h>
#include <math.h>

typedef struct {
  bool A;
  bool B;
  bool C;
  bool D;
  bool E;
  bool F;
  bool G;
} matrizDigitos;

matrizDigitos *matriz = (matrizDigitos *)malloc(sizeof(matrizDigitos));

bool flag = 1;
int *senhaAtual;
int *senhaCadastrada;
int cont = -1;
int cont2 = 10;
int qtdDigitos;
bool flag2 = 1;

matrizDigitos updateMatriz(matrizDigitos mat, matrizDigitos upd) {
  mat = upd;

  mat.A ? digitalWrite(13, HIGH) : digitalWrite(13, LOW);
  mat.B ? digitalWrite(12, HIGH) : digitalWrite(12, LOW);
  mat.C ? digitalWrite(11, HIGH) : digitalWrite(11, LOW);
  mat.D ? digitalWrite(10, HIGH) : digitalWrite(10, LOW);
  mat.E ? digitalWrite(9, HIGH) : digitalWrite(9, LOW);
  mat.F ? digitalWrite(8, HIGH) : digitalWrite(8, LOW);
  mat.G ? digitalWrite(7, HIGH) : digitalWrite(7, LOW);
  return mat;
}

matrizDigitos numExibe(matrizDigitos *mat) {
  matrizDigitos upd;
  switch (cont2++) {
  case 0:
    *mat = updateMatriz(*mat, upd = {0, 1, 1, 0, 0, 0, 0});
    break;
  case 1:
    *mat = updateMatriz(*mat, upd = {1, 1, 0, 1, 1, 0, 1});
    break;
  case 2:
    *mat = updateMatriz(*mat, upd = {1, 1, 1, 1, 0, 0, 1});
    break;
  case 3:
    *mat = updateMatriz(*mat, upd = {0, 1, 1, 0, 0, 1, 1});
    break;
  case 4:
    *mat = updateMatriz(*mat, upd = {1, 0, 1, 1, 0, 1, 1});
    break;
  case 5:
    *mat = updateMatriz(*mat, upd = {0, 0, 1, 1, 1, 1, 1});
    break;
  case 6:
    *mat = updateMatriz(*mat, upd = {1, 1, 1, 0, 0, 0, 0});
    break;
  case 7:
    *mat = updateMatriz(*mat, upd = {1, 1, 1, 1, 1, 1, 1});
    break;
  case 8:;
    *mat = updateMatriz(*mat, upd = {1, 1, 1, 0, 0, 1, 1});
    break;
  default:
    *mat = updateMatriz(*mat, upd = {1, 1, 1, 1, 1, 1, 0});
    cont2 = 0;
    break;
  }
  return *(mat);
}

int CriaSenha(int *senha, int qtdAtual, int qtdDigitos, int soma) {
  if (qtdAtual == qtdDigitos)
    return soma;
  else
    CriaSenha(senha, qtdAtual++, qtdDigitos,
              soma + (senha[qtdAtual] * pow(10, (qtdAtual))));
}
void ChecaSenha(int *senhaAtual, int qtdAtual, int qtdDigitos,
                int senhaCadastrada, bool confere) {
  if (qtdAtual == qtdDigitos) {
    if (confere) {
      digitalWrite(6, HIGH);
      delay(5000);
      digitalWrite(6, LOW);
    } else {
      digitalWrite(5, HIGH);
      delay(5000);
      digitalWrite(5, LOW);
    }
  } else
    ChecaSenha(senhaAtual, qtdAtual++, qtdDigitos, senhaCadastrada,
               confere * (senhaAtual[qtdAtual] * pow(10, (qtdAtual)) ==
                          senhaCadastrada));
}

void setup() {
  Serial.begin(9600);

  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, INPUT);
  pinMode(2, INPUT);
}

void loop() {
  if (digitalRead(4)) {
    delay(200);
    *matriz = numExibe(matriz);
  }
  if (digitalRead(2)) {
    delay(250);
    if (flag) {
      senhaAtual = (int *)malloc(cont2 * sizeof(int));
      senhaCadastrada = (int *)malloc(cont2 * sizeof(int));
      if (senhaAtual == NULL || senhaCadastrada == NULL)
        exit;
      qtdDigitos = cont2;
      flag = 0;
    } else {
      senhaAtual[++cont] = cont2;
      if (cont == qtdDigitos) {
        if (flag2) {
          *(senhaCadastrada) = CriaSenha(senhaAtual, 0, qtdDigitos, 0);
          flag2 = 0;
        } else {
          ChecaSenha(senhaAtual, 0, qtdDigitos, *senhaCadastrada, 0);
        }
        cont = 0;
      }
    }
  }
}
