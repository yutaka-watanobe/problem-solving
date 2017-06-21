
bool isLeap(int y){
  return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0);
}

//0:Sun .. 6:Sat
int zeller(int y, int m, int d){
  if(m <= 2) m += 12, --y;
  return (y + y/4 - y/100 + y/400 + (13*m + 8) / 5 + d) % 7;
}
