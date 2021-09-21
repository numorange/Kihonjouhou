#ifndef BITAP_H
#define BITAP_H
//------------------------------------------------
#include <stdio.h>

//------------------------------------------------
//  マクロ定義(Macro definition)
//------------------------------------------------
#define ABET_NUM  (26)
#define MOJI_MAX  (16+1)
// #define GBITMASK     // 設問1、2
#define GBITMASK_REGEX  // 設問3

//------------------------------------------------
//  型定義(Type definition)
//------------------------------------------------
typedef struct
{
  char Text[MOJI_MAX]; // 対象文字列
  char Pat[MOJI_MAX];  // 検索文字列
  int *Mask;
}bittap;

//------------------------------------------------
//  プロトタイプ宣言(Prototype declaration)
//------------------------------------------------
int BitapMatch(bittap bt);

#endif
