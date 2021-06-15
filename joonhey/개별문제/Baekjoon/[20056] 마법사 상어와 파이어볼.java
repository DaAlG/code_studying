import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

class Main {

	static int[] di; // = { -1, -1, 0, 1, 1, 1, 0, -1 };
	static int[] dj; // = { 0, 1, 1, 1, 0, -1, -1, -1 };
	static int N, M, K;

	static class Fireball {
		int mass;
		int direction;
		int speed;

		public Fireball(int mass, int speed, int direction) {
			this.mass = mass;
			this.direction = direction;
			this.speed = speed;
		}
	}

//	r,c -> list
	static LinkedList<Fireball>[][] map;
	static LinkedList<Fireball>[][] map2;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		LinkedList<Fireball> list;
		di = new int[] { -1, -1, 0, 1, 1, 1, 0, -1 };
		dj = new int[] { 0, 1, 1, 1, 0, -1, -1, -1 };
		N = Integer.parseInt(st.nextToken());
		map = new LinkedList[N][N];
		map2 = new LinkedList[N][N];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = new LinkedList<>();
				map2[i][j] = new LinkedList<>();
			}
		}
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		int r, c, m, s, d;
//		파이어볼 입력
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
//			인덱스 주의.
			r = Integer.parseInt(st.nextToken()) - 1;
			c = Integer.parseInt(st.nextToken()) - 1;
			m = Integer.parseInt(st.nextToken());
			s = Integer.parseInt(st.nextToken());
			d = Integer.parseInt(st.nextToken());
//			맵에 파이어볼 넣기.
			map[r][c].offer(new Fireball(m, s, d));
		}

//		명령대로 이동 시작.
		int ni = 0, nj = 0;
		for (int i = 0; i < K; i++) {
			for (int row = 0; row < N; row++) {
				for (int col = 0; col < N; col++) {
					list = map[row][col];
//				자신의 방향 di로 속력si만큼 이동한다. 1과 N은 연결되어있음에 유의
					while (!list.isEmpty()) {
						Fireball ball = list.poll();
						int dist_i = di[ball.direction] * ball.speed;
						int dist_j = dj[ball.direction] * ball.speed;
						ni = row + dist_i;
						nj = col + dist_j;
//					인덱스가 범위 밖일 경우 추가작업.
						if (ni < 0 || ni >= N || nj < 0 || nj >= N) {
//						더해질 거리가 너무 긺 -> 5개 짜리 배열에서 5만큼 위치를 더하면 한바퀴 돈다
							dist_i = Math.abs(dist_i) % N;
							dist_j = Math.abs(dist_j) % N;
//						i 인덱스
							if (ni < 0) {
//							N을 더해주는 이유: row - dist값이 음수일 경우, 양수일 경우 둘 다 한번에 처리하기 위해
//							row - dist의 값이 0 미만으로 나올 경우, N을 더해줘야 한다.
//							반면 0 이상의 정상적인 값이 나올 경우 아무런 가공(?)도 필요 없다.

//							이 두 경우를 if문으로 나눠서 계산할 수도 있겠지만, 
//							미리 N을 더해놓으면 row - dist 값이 0 미만일 때도 처리 가능하고 + 한바퀴 돈 셈이라 본래 위치는 같음), 
//							row - dist값이 이미 0 이상이어서 +N으로 인해 N을 넘어간다고 해도 이 다음에 N으로 %해주면 원래 값으로 돌아옴 .
								ni = (row - dist_i + N) % N;
								// ni = row - dist_i;
//							if(ni < 0)
////							row 기준으로 다음 값을 계산하고  그 값이,(왼쪽으로)범위를 초과한 만큼 N에서 빼준당.
//								ni += N;
							} else if (ni >= N) {
								ni = (row + dist_i) % N;
							}
//						j 인덱스
							if (nj < 0) {
								nj = (col - dist_j + N) % N;
							} else if (nj >= N) {
								nj = (col + dist_j) % N;
							}
						}

//					System.out.println(row+"행"+col+"열=>"+" "+ni+"행 "+nj+"열");
//				위치 계산 완료 후, 그 위치에 넣어주기 -> 새로운 map에 넣어야 함. 기존 map의 list를 순회하는 구조이므로
//					거기에 새 원소를 넣어주면 list에 계속해서 
//					새로운 원소가 생기므로 순회가 안끝남
						map2[ni][nj].offer(new Fireball(ball.mass, ball.speed, ball.direction));
					} // 공 하나
				} // 위치 하나
			}
//			명령 하나 끝남 -> map2 poll해서 계산(파이어볼이 네 개로 나뉘어지는 경우를 계산 ) 후 map 에 넣어줌.
			for (int row = 0; row < N; row++) {
				for (int col = 0; col < N; col++) {
					list = map2[row][col];
					int lSize = list.size();
//				파이어볼이 두 개 이상 -> 네 개로 갈린다.
					if (lSize >= 2) {
						int mSum = 0, sSum = 0;
//					맨 처음 방향이 홀수인지 짝수인지 기록
						int flag = list.get(0).direction % 2;
//					모두 방향이 같은가?
						boolean allSame = true;
						while (!list.isEmpty()) {
							Fireball ball = list.poll();
							mSum += ball.mass;
							sSum += ball.speed;
//						모두 같은 경우에만 계속 검사하기
							if (allSame) {
								if (flag != ball.direction % 2)
									allSame = false;
							}
						}
						mSum /= 5;
						sSum /= lSize;
//					질량이 0이면 소멸
						if (mSum != 0) {
//					네 개의 파이어볼 삽입
							int newDirection;
//					방향이 모두 홀수이거나 짝수면 0,2,4,6
							if (allSame)
								newDirection = 0;
//					방향이 각자 다르면 1,3,5,7
							else
								newDirection = 1;

							for (int ballIdx = 0; ballIdx < 4; ballIdx++, newDirection += 2) {
								map[row][col].offer(new Fireball(mSum, sSum, newDirection));
							}
						}

					}
					// 개수가 하나면 쪼개지지 말고 그냥 있어
					else if (lSize == 1) {
						map[row][col].offer(list.poll());
					}
				}
			}

		} // 이동 K개 끝남
//		남아있는 파이어볼 질량의 합
		int res = 0;
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) {
				list = map[row][col];
				for (Fireball ball : list) {
					res += ball.mass;
				}
			}
		}
		System.out.println(res);
	}
}