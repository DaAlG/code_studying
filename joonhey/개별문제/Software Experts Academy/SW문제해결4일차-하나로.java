package day0323;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Solution {
	static StringBuilder sb; // 정답 출력용
	static double res;
	static int N;
	static double E;
	static boolean[] visited;

	static class Vertex {
		int x;
		int y;

		public Vertex(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static Vertex[] list; // 테케마다 초기화
	static double[] minDist;

	// 정점 크기 만큼 put(시작 정점은 0)
	public static void makePq() {
		// 시작 정점과의 거리는 0
		minDist[0] = 0;
		// 나머지 애들은 일단 최대로.
		for (int i = 1; i < N; i++) {
			minDist[i] = Double.MAX_VALUE;
		}
	}

	// vert1과 vert2 사이의 거리 리턴.
	public static double getDistance(int vert1, int vert2) {
		// (x1-x2)2 + (y1-y2)2 의 루트
		return Math.sqrt(Math.pow(list[vert1].x - list[vert2].x, 2) + Math.pow(list[vert1].y - list[vert2].y, 2));
	}

	// 모든 정점을 다 방문할 때 까지
	public static void makeMst() {
		for (int i = 0; i < N; i++) {
			// 1. 현재 가장 가까운 vertex 방문. -> visited 안한 것 중에.
			double min = Double.MAX_VALUE;
			int closeVertex = 0;
			for (int j = 0; j < N; j++) {
				if (minDist[j] < min && !visited[j]) {
					min = minDist[j];
					closeVertex = j;
				}
			}

			// 2. 걔방문하고 인근 업데이트.
			visited[closeVertex] = true;
			res += Math.pow(min, 2) * E;
			for (int j = 0; j < N; j++) {
				if (!visited[j]) {
					double curDist = getDistance(closeVertex, j);
					if (minDist[j] > curDist) {
						minDist[j] = curDist;

					}
				}
			}

		}

	}

	public static void main(String[] args) throws IOException {
		sb = new StringBuilder("");
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		StringTokenizer st;

		for (int t = 1; t <= T; t++) {
			/// 테케별 초기화 - 테케별 섬 길이, 정점 배열, 섬 개수.//
			res = 0; // 테케별 정답.
			N = Integer.parseInt(br.readLine());
			list = new Vertex[N];// 섬들 배열 초기화.
			visited = new boolean[N];
			minDist = new double[N];
			// x좌표
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++) {
				// y좌표 일단 0으로..
				list[i] = new Vertex(Integer.parseInt(st.nextToken()), 0);
			}
			// y좌표
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++) {
				list[i].y = Integer.parseInt(st.nextToken());
			}
			// 환경 부담 세율
			E = Double.parseDouble(br.readLine());
			// pq 만들기
			makePq();
			// 그때 그때 최소값 제곱하고 E 곱해서 res에 더해주기.
			makeMst();
			// 출력 저장
			sb.append("#").append(t).append(" ").append(Math.round(res)).append("\n");
		}
		System.out.println(sb);
	}
}
