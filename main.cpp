#include <iostream>
#include "trie.h"

int main() {
  trie a;
  a.insert("rod");
  a.insert("rip");
  a.insert("avatar");
  a.insert("ave");
  a.insert("aver");
  a.insert("avion");
  a.insert("avionsito");
  a.insert("avioneta");
  a.erase("avionazo");
  a.erase("avionsito");
  a.erase("heap");
  a.print();
}