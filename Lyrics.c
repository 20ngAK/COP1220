// COP-1220 Section 86392 
// Assignment 1-2 - Lyrics
// Display the 4 lines of lyrics.

#include <stdio.h>
#include <string.h>

int main() {
  char lyric1[200] = "Oh, well imagine /\nAs I'm pacing the pews in a church corridor /\nAnd I can't help but to hear /\nNo, I can't help but to hear an exchanging of words...";
  char lyric2[200] = "\nOh-oh-oh-oh-oh;\noh-oh-oh-oh,\noh-oh-oh /\nCaught in a bad romance...";
  char lyric3[200] = "\nComing out my cage\nAnd I've been doing just fine\nGotta gotta be down\nBecause I want it all";
  char lyric4[200] = "\nNow, this is a story all about how\nMy life got flipped-turned upside down\nAnd I'd like to take a minute\nJust sit right there\nI'll tell you how I became the prince of a town called Bel-Air";

  printf("%s\n", lyric1);
  printf("%s\n", lyric2);
  printf("%s\n", lyric3);
  printf("%s", lyric4);


  return 0;
}