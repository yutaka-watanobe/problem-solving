#include <vector>
using namespace std;
#include <cstdio>
#include <cstring>
#include <cctype>

const char *ENWS = "ENWS";
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

int W, H;
char fld[100][100];

int N;
int pox[1000], poy[1000], dir[1000];
bool done[1000];

bool usd[100][100];
pair<int, int> mov[100][100];

void myassert(bool f) {
  if (!f) {
    for (;;) {
      puts("assertion failed!");
    }
  }
}

int main() {
  for (;;) {
    scanf("%d%d", &W, &H);
    if (!(W|H)) return 0;
    myassert(1 <= W && W <= 30 && 1 <= H && H <= 30);
    N = 0;
    for (int y = 0; y < H; y++) {
      for (int x = 0; x < W; x++) {
        scanf(" %c", &fld[y][x]);
        myassert(strchr("#.XENWS", fld[y][x]) != NULL);

        if (isalpha(fld[y][x]) && fld[y][x] != 'X') {
          pox[N] = x;
          poy[N] = y;
          dir[N] = strchr(ENWS, fld[y][x]) - ENWS;
          N++;
          fld[y][x] = '.';
        }
      }
    }

    if (!N) {
      myassert(false);
      puts("0");
      continue;
    }

    memset(done, 0, sizeof(done));
    int donen = 0;
    for (int t = 1; t <= 180; t++) {
      // for (int i = 0; i < N; i++) printf("(%d,%d) ", pox[i], poy[i]); puts("");

      for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
          mov[y][x] = make_pair(999, -1);
        }
      }

      memset(usd, 0, sizeof(usd));
      for (int i = 0; i < N; i++) {
        if (done[i]) continue;
        usd[poy[i]][pox[i]] = true;
      }

      for (int i = 0; i < N; i++) {
        // printf("%d: %d %d %d\n", i, pox[i], poy[i], dir[i]);
        if (done[i]) continue;
        int d = dir[i];
        for (int dd = -1; dd <= 2; dd++) {
          int td = (d + dd + 4) % 4;
          int ty = poy[i] + dy[td];
          int tx = pox[i] + dx[td];
          if (fld[ty][tx] != '#' && !usd[ty][tx]) {
            dir[i] = td;
            break;
          }
        }

        int ty = poy[i] + dy[dir[i]];
        int tx = pox[i] + dx[dir[i]];
        if (fld[ty][tx] == '#') continue;
        mov[ty][tx] = min(mov[ty][tx], make_pair((dir[i] + 2) % 4, i));
        // printf("%d %d\n", mov[ty][tx].first, mov[ty][tx].second);
      }

      for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
          if (mov[y][x].second != -1) {
            int i = mov[y][x].second;
            pox[i] = x;
            poy[i] = y;
            if (fld[y][x] == 'X') {
              done[i] = true;
              donen++;
            }
          }
        }
      }

      if (donen == N) {
        printf("%d\n", t);
        goto done;
      }
    }
    puts("NA");
  done:;
  }
}


