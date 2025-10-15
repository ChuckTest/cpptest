#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <map>
#include <windows.h>

using namespace std;

// 定义无穷大 (根据您的要求)
const int INF = 32767;

// 定义图结构
struct Graph
{
    int V; // 顶点数
    // 邻接矩阵：g.edges[i][j]
    // > 0 且 < INF: 边权
    // 0: i=j
    // INF: 无边 (i != j)
    vector<vector<int>> edges;
    vector<char> vertex_names; // 存储顶点名称，便于输出
};

/**
 * @brief Prim 算法构造最小生成树 (MST)
 * * @param g 带权无向图的邻接矩阵表示
 * @param v MST 的起始顶点编号 (从 0 开始)
 */
void Prim(const Graph &g, int v)
{
    int V = g.V;

    if (v < 0 || v >= V)
    {
        cerr << "错误: 起始顶点编号无效!" << endl;
        return;
    }

    // 用于将数字编号映射回字母，方便输出
    const vector<char> vertex_names = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

    // closest[j]: 存储 V-U 中的顶点 j 到 U 中距离最近的顶点编号
    vector<int> closest(V);
    // lowcost[j]: 存储 V-U 中的顶点 j 到 U 的最小边权
    // lowcost[j] = 0 表示 j 属于 U
    vector<int> lowcost(V);

    // 1. 初始化数组 (U 初始只包含起始顶点 v)
    for (int j = 0; j < V; ++j)
    {
        lowcost[j] = g.edges[v][j]; // j 到 v 的边权
        closest[j] = v;             // j 到 U 最近的点是 v
    }

    // 标记起始顶点 v 已加入 U
    // 根据约定: lowcost[j] = 0 表示 j 属于 U
    lowcost[v] = 0;

    int mst_weight = 0;
    int edge_count = 0;

    cout << "Prim 算法构造最小生成树 (从顶点 " << vertex_names[v] << " 开始):" << endl;
    cout << "-----------------------------------" << endl;

    // 2. 迭代 V-1 次，每次将 V-U 中一个顶点加入 U
    for (int i = 1; i < V; ++i)
    {

        // a) 在 V-U (即 lowcost[j] > 0) 中，寻找 lowcost 最小的顶点 k
        int min_cost = INF + 1; // 确保 min_cost 被正确更新
        int k = -1;             // 将要加入 U 的顶点

        for (int j = 0; j < V; ++j)
        {
            // lowcost[j] > 0 且 lowcost[j] < INF 表示 j 属于 V-U 且可达
            if (lowcost[j] > 0 && lowcost[j] < min_cost)
            {
                min_cost = lowcost[j];
                k = j;
            }
        }

        // 检查图是否连通
        if (k == -1)
        {
            cout << "警告: 图不连通或发生错误!" << endl;
            break;
        }

        // b) 将顶点 k 加入 U
        // 选中边 (closest[k], k)
        cout << "  添加边: (" << vertex_names[closest[k]] << ", " << vertex_names[k]
             << ")，权重: " << min_cost << endl;
        mst_weight += min_cost;
        edge_count++;

        // 标记 k 已加入 U (根据约定: lowcost[k] = 0)
        lowcost[k] = 0;

        // c) 更新 lowcost 和 closest 数组
        // 遍历所有属于 V-U 的顶点 j
        for (int j = 0; j < V; ++j)
        {
            // lowcost[j] > 0 表示 j 属于 V-U
            if (lowcost[j] > 0)
            {

                // 检查 k 到 j 的新边是否比 lowcost[j] 更小
                if (g.edges[k][j] < lowcost[j])
                {
                    lowcost[j] = g.edges[k][j]; // 更新最小权重
                    closest[j] = k;             // 更新最近的 U 中的顶点
                }
            }
        }
    }

    cout << "-----------------------------------" << endl;
    cout << "最小生成树的总权重: " << mst_weight << endl;
}

// 第一个图的构造函数 (A-G)
Graph create_graph_1()
{
    const int V_COUNT = 7;
    Graph g;
    g.V = V_COUNT;
    g.vertex_names = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

    // 初始化邻接矩阵为 0 (对角线) 或 INF (非对角线)
    g.edges.resize(V_COUNT, vector<int>(V_COUNT, INF));
    for (int i = 0; i < V_COUNT; ++i)
    {
        g.edges[i][i] = 0;
    }

    // 边和权重: {u, v, weight} (A=0, B=1, C=2, D=3, E=4, F=5, G=6)
    vector<tuple<int, int, int>> edges_data = {
        {0, 3, 9}, {0, 1, 2}, {0, 5, 5}, // AD 9, AB 2, AF 5
        {1, 5, 8},
        {5, 6, 1},
        {1, 6, 4}, // BF 8, FG 1, BG 4
        {2, 6, 6},
        {1, 2, 7},
        {4, 2, 10}, // CG 6, BC 7, EC 10
        {1, 4, 3},
        {1, 3, 1},
        {3, 4, 2} // BE 3, BD 1, DE 2
    };

    for (const auto &edge : edges_data)
    {
        int u = get<0>(edge);
        int v = get<1>(edge);
        int weight = get<2>(edge);
        g.edges[u][v] = weight;
        g.edges[v][u] = weight; // 无向图
    }
    return g;
}

// 第二个图的构造函数 (0-6)
Graph create_graph_2()
{
    const int V_COUNT = 7;
    Graph g;
    g.V = V_COUNT;
    // 使用数字作为顶点名称，但存储为字符，方便在 Prim 中通用输出
    g.vertex_names = {'0', '1', '2', '3', '4', '5', '6'};

    // 初始化邻接矩阵
    g.edges.resize(V_COUNT, vector<int>(V_COUNT, INF));
    for (int i = 0; i < V_COUNT; ++i)
    {
        g.edges[i][i] = 0;
    }

    // 边和权重: {u, v, weight} (顶点直接使用数字编号)
    vector<tuple<int, int, int>> edges_data = {
        {0, 1, 28}, {0, 5, 10}, {5, 4, 25}, {4, 6, 24}, {4, 3, 22}, {6, 1, 14}, {6, 3, 18}, {2, 1, 16}, {2, 3, 12}};

    for (const auto &edge : edges_data)
    {
        int u = get<0>(edge);
        int v = get<1>(edge);
        int weight = get<2>(edge);
        g.edges[u][v] = weight;
        g.edges[v][u] = weight; // 无向图
    }
    return g;
}

// 示例主函数
int main()
{

    SetConsoleOutputCP(65001); // 控制台输出 UTF-8

    // --- 图 1: A-G ---
    Graph g1 = create_graph_1();
    int start_node_g1 = 0; // 从 A(0) 开始
    cout << "\n--- 处理图 1 (顶点 A-G) ---" << endl;
    Prim(g1, start_node_g1);

    // --- 图 2: 0-6 ---
    Graph g2 = create_graph_2();
    int start_node_g2 = 0; // 从 0 开始
    cout << "\n--- 处理图 2 (顶点 0-6) ---" << endl;
    Prim(g2, start_node_g2);

    system("pause");
    return 0;
}