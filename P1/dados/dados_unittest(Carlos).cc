// dados_unittest.cc: Juan A. Romero
// A sample program demonstrating using Google C++ testing framework.
//


// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include "dados.h"
#include "gtest/gtest.h"

// Tests the c'tor.
TEST(Dados, Constructor) {
  Dados d;
  
  EXPECT_EQ(1, d.getDado1());
  EXPECT_EQ(1, d.getDado2());
  EXPECT_EQ(2, d.getSuma());
  
}

// Tests operación lanzamiento
TEST(Dados, Lanzamiento) {
  Dados d;
  for (int i=0; i<100; i++){
  d.lanzamiento();
  EXPECT_GT(d.getDado1(), 0);
  EXPECT_LT(d.getDado1(), 7);
  EXPECT_GT(d.getDado2(), 0);
  EXPECT_LT(d.getDado2(), 7);
}

}

// Tests operación suma
TEST(Dados, Suma) {
  Dados d;
  
  EXPECT_EQ(d.getDado1()+d.getDado2(), d.getSuma());
}

//Test operación resta
TEST(Dados, Diferencia) {
  Dados d;
  
  d.lanzamiento();

  if(d.getDado1()>d.getDado2())
    EXPECT_EQ(d.getDado1()-d.getDado2(), d.getDiferencia());
  else EXPECT_EQ(d.getDado2()-d.getDado1(), d.getDiferencia());
}

// Tests modificadores
TEST(Dados, Modificadores) {
  Dados d;
  
  EXPECT_FALSE(d.setDado1(9));
  EXPECT_FALSE(d.setDado1(-9));
  EXPECT_FALSE(d.setDado2(9));
  EXPECT_FALSE(d.setDado2(-9));
  d.setDado1(3);
  EXPECT_EQ(3, d.getDado1());
  d.setDado2(2);
  EXPECT_EQ(2, d.getDado2());
  EXPECT_EQ(5, d.getSuma());
}

//Test getLanzamientos
TEST(Dados, GetLanzamientos) {
  Dados d;

  EXPECT_EQ(d.getLanzamientos1(), 0);
  EXPECT_EQ(d.getLanzamientos2(), 0);

  d.lanzamiento();
  d.lanzamiento();

  EXPECT_EQ(d.getLanzamientos1(), 2);
  EXPECT_EQ(d.getLanzamientos2(), 2);
  
  d.setDado1(5);

  EXPECT_EQ(d.getLanzamientos1(), 3);
  EXPECT_EQ(d.getLanzamientos2(), 2);

  d.setDado2(4);
  
  EXPECT_EQ(d.getLanzamientos1(), 3);
  EXPECT_EQ(d.getLanzamientos2(), 3);

  d.setDado1(0);
  d.setDado2(8);
  
  EXPECT_EQ(d.getLanzamientos1(), 3);
  EXPECT_EQ(d.getLanzamientos2(), 3);
  
}

//Test media
TEST(Dados, Media) {
  Dados d;
  float mediaimprov1=0, mediaimprov2=0, 
  valoresd1 = 0, valoresd2 = 0;
  
  EXPECT_EQ(0, d.getMedia1());
  EXPECT_EQ(0, d.getMedia2());

  d.lanzamiento();
  valoresd1+=d.getDado1();
  valoresd2+=d.getDado2();
  EXPECT_NEAR(d.getDado1(), d.getMedia1(), 0.0001);
  EXPECT_NEAR(d.getDado2(), d.getMedia2(), 0.0001);
  
  d.setDado1(5);
  d.setDado2(3);
  valoresd1+=d.getDado1();
  valoresd2+=d.getDado2();
  mediaimprov1 = valoresd1/d.getLanzamientos1();
  mediaimprov2 = valoresd2/d.getLanzamientos2();
  EXPECT_NEAR(mediaimprov1, d.getMedia1(), 0.0001);
  EXPECT_NEAR(mediaimprov2, d.getMedia2(), 0.0001);

}

//Test getUltimos
TEST(Dados, GetUltimos) {
  Dados d;
  int v1[5], v2[5];

  d.getUltimos1(v1);
  d.getUltimos2(v2);

  for(int i=0 ; i<5 ; i++) {
    EXPECT_EQ(v1[i], 0);
    EXPECT_EQ(v2[i], 0);
  }

  d.setDado1(5);
  d.setDado2(2);

  d.setDado1(4);
  d.setDado2(3);

  d.setDado1(3);
  d.setDado2(4);

  d.setDado1(2);
  d.setDado2(5);

  d.lanzamiento();

  d.getUltimos1(v1);
  d.getUltimos2(v2);

  EXPECT_EQ(v1[4], 5);
  EXPECT_EQ(v2[4], 2);
  EXPECT_EQ(v1[3], 4);
  EXPECT_EQ(v2[3], 3);
  EXPECT_EQ(v1[2], 3);
  EXPECT_EQ(v2[2], 4);
  EXPECT_EQ(v1[1], 2);
  EXPECT_EQ(v2[1], 5);
  EXPECT_EQ(v1[0], d.getDado1());
  EXPECT_EQ(v2[0], d.getDado2());

}
