#include<iostream>
using namespace std;

	int main() {
		int N, team;
		int Atime = 0, Btime = 0, Ascore = 0, Bscore = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			int hour, min, savehour, savem;
			scanf("%d", &team);
			scanf("%2d:%2d", &hour, &min);
			if (i != 0) {
				if (Ascore > Bscore) {
					Atime += ((hour - savehour) * 60 + (min - savem));
				}
				else if (Ascore < Bscore) {
					Btime += ((hour - savehour) * 60 + (min - savem));
				}
			}
			if (team == 1)
				Ascore++;
			if (team == 2)
				Bscore++;
			savehour = hour;
			savem = min;
			if (i == N - 1) {
				if (Ascore > Bscore) {
					Atime += ((48 - savehour) * 60 + (-min));
				}
				else if (Ascore < Bscore) {
					Btime += ((48 - savehour) * 60 + (-min));
				}
			}
		}
		printf("%02d:%02d\n%02d:%02d", Atime / 60, Atime % 60, Btime / 60, Btime % 60);
	}
