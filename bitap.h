/* 令和元年 秋 午後 問8 */
/* Bitap法を使った文字列検索 */

#include <string.h>
#include "bitap.h"

int Index(char moji)
/* 英大文字を設定するとアルファベッド順（1<=n<=26）を返す */
{
  return moji - 'A' + 1;
}

int GenerateBitMaskRegex(bittap bt)
{
  size_t OriginalPatLen_t = strlen(bt.Pat);
  int OriginalPatLen = (int)OriginalPatLen_t;
  int PatLen = 0;
  int Mode = 0;

  for(int i = 1; i <= ABET_NUM; i++)
  {
    bt.Mask[i] = 0; // 初期化
  }
  for(int i = 1; i <= OriginalPatLen; i++)
  {
    if (bt.Pat[i-1] == '[')
    {
      Mode = 1;
      PatLen = PatLen + 1;
    } else {
      if (bt.Pat[i-1] == ']')
      {
        Mode = 0;
      } else {
        if (Mode == 0)
        {
          PatLen = PatLen + 1;
        }
        bt.Mask[Index(bt.Pat[i-1])] |= (1 << (PatLen-1));
      }
    }
  }
  return PatLen;
}

int GenerateBitMask(bittap bt)
{
  size_t PatLen_t = strlen(bt.Pat); // ポインタ形式で配列を指定しているためsizeofでは要素数が取得できないのでstrlenを使う
  int PatLen = (int)PatLen_t;

  for(int i = 1; i <= ABET_NUM; i++)
  {
    bt.Mask[i] = 0;  // 初期化
  }

  for(int i = 1; i <= PatLen; i++)
  {
    bt.Mask[Index(bt.Pat[i-1])] |= (1 << (i-1));  // i番目のフラグを立てる
  }
  return PatLen;
}

int BitapMatch(bittap bt)
{
  size_t TextLen_t = strlen(bt.Text);
  int TextLen = (int)TextLen_t;
#if defined(GBITMASK)
  int PatLen = GenerateBitMask(bt);
#elif defined(GBITMASK_REGEX)
  int PatLen = GenerateBitMaskRegex(bt);
#endif
  int Status = 0;
  int Goal = 0;
  Goal |= (1 << (PatLen-1));
  
  for (int i = 1; i <= TextLen; i++)
  {
    Status = (Status << 1) | 1;
    Status = Status & bt.Mask[Index(bt.Text[i-1])];
    if ((Status & Goal) != 0)
    {
      return (i - PatLen + 1);
    }
  }
  return (-1);
}
