#include <stdio.h>
#include "bitap.h"

int main()
{
  /* 令和元年 秋 午後 問8 */
  /* Bitap法を使った文字列検索 */
  /* https://maehrm.hatenablog.com/entry/2019/11/04/150429 */
  /* https://www.fe-siken.com/kakomon/01_aki/pm08.html */
  bittap bt;
  int mask[ABET_NUM];
  bt.Mask = mask;
  int MatchNumber = 0;

  printf("対象文字列を入力してください。\n※何も入力しないとデフォルトになります。\n");
  // gets(bt.Text);
  fgets(bt.Text, sizeof bt.Text, stdin);
  if (bt.Text[0] == '\n')
  {
    sprintf(bt.Text, "%s", "AACBBAACABABAB"); // 対象文字列
  }

  printf("検索文字列を入力してください。\n");
  // gets(bt.Pat);
  fgets(bt.Pat, sizeof bt.Pat, stdin);
  if (bt.Pat[0] == '\n')
  {
#if defined(GBITMASK)
    sprintf(bt.Pat, "%s",  "ACABAB");  // 検索文字列
#elif defined(GBITMASK_REGEX)
    sprintf(bt.Pat, "%s",  "A[BC]B");  // 検索文字列
#endif
  }
  printf("対象文字列は%s\n検索文字列は%s\n",bt.Text, bt.Pat);

  MatchNumber = BitapMatch(bt);
  if (MatchNumber == -1)
  {
    printf("対象文字列に検索文字列はありません。\n");
  } else {
    printf("%sは%d番目にあります。\n", bt.Pat, (MatchNumber+1));
  }
}
