#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <tuple>
#include <string>
#include <windows.h>

using namespace std;

// 定义无穷大 (根据您的要求)
const int INF = 32767;

// 定义图结构
struct Graph
{
    int V; // 顶点数
    vector<vector<int>> edges;
    vector<string> vertex_names; // 使用 std::string 存储顶点名称
};

// 第一个图的构造函数 (A-G)
Graph create_graph_1()
{
    const int V_COUNT = 7;
    Graph g;
    g.V = V_COUNT;
    g.vertex_names = {"A", "B", "C", "D", "E", "F", "G"};

    g.edges.resize(V_COUNT, vector<int>(V_COUNT, INF));
    for (int i = 0; i < V_COUNT; ++i)
        g.edges[i][i] = 0;

    // 边和权重: {u, v, weight} (A=0, B=1, C=2, D=3, E=4, F=5, G=6)
    vector<tuple<int, int, int>> edges_data = {
        {0, 3, 9}, {0, 1, 2}, {0, 5, 5}, {1, 5, 8}, {5, 6, 1}, {1, 6, 4}, {2, 6, 6}, {1, 2, 7}, {4, 2, 10}, {1, 4, 3}, {1, 3, 1}, {3, 4, 2}};

    for (const auto &edge : edges_data)
    {
        int u = get<0>(edge);
        int v = get<1>(edge);
        int weight = get<2>(edge);
        g.edges[u][v] = weight;
        g.edges[v][u] = weight;
    }
    return g;
}

// 第二个图的构造函数 (0-6)
Graph create_graph_2()
{
    const int V_COUNT = 7;
    Graph g;
    g.V = V_COUNT;

    // 使用 std::string 存储数字顶点名称 "0", "1", ...
    g.vertex_names.reserve(V_COUNT);
    for (int i = 0; i < V_COUNT; ++i)
    {
        g.vertex_names.push_back(to_string(i));
    }

    g.edges.resize(V_COUNT, vector<int>(V_COUNT, INF));
    for (int i = 0; i < V_COUNT; ++i)
        g.edges[i][i] = 0;

    // 边和权重: {u, v, weight} (顶点直接使用数字编号)
    vector<tuple<int, int, int>> edges_data = {
        {0, 1, 28}, {0, 5, 10}, {5, 4, 25}, {4, 6, 24}, {4, 3, 22}, {6, 1, 14}, {6, 3, 18}, {2, 1, 16}, {2, 3, 12}};

    for (const auto &edge : edges_data)
    {
        int u = get<0>(edge);
        int v = get<1>(edge);
        int weight = get<2>(edge);
        g.edges[u][v] = weight;
        g.edges[v][u] = weight;
    }
    return g;
}

/**
 * @brief Prim 算法构造最小生成树 (MST)
 * @param g 带权无向图的邻接矩阵表示
 * @param v MST 的起始顶点编号 (从 0 开始)
 */
void Prim(const Graph &g, int v)
{
    int V = g.V;

    // ... (初始化逻辑保持不变)
    vector<int> closest(V);
    vector<int> lowcost(V);

    for (int j = 0; j < V; ++j)
    {
        lowcost[j] = g.edges[v][j];
        closest[j] = v;
    }
    lowcost[v] = 0;

    int mst_weight = 0;
    int edge_count = 0;

    cout << "\n===================================" << endl;
    cout << "Prim 算法结果 (从顶点 " << g.vertex_names[v] << " 开始):" << endl;
    cout << "-----------------------------------" << endl;

    // 2. 迭代 V-1 次
    for (int i = 1; i < V; ++i)
    {

        // a) 在 V-U (lowcost[j] > 0) 中，寻找 lowcost 最小的顶点 k
        int min_cost = INF + 1;
        int k = -1;

        cout << "  当前 V-U 集合中的候选边 (lowcost > 0 且 < INF):" << endl;
        bool has_candidate = false;
        for (int j = 0; j < V; ++j)
        {
            if (lowcost[j] > 0 && lowcost[j] < INF)
            {
                has_candidate = true;
                cout << "    * 边 (" << g.vertex_names[j] << ", " << g.vertex_names[closest[j]]
                     << ")，权重: " << lowcost[j] << endl;
            }
        }
        if (!has_candidate)
        {
            cout << "    (没有可达的候选边，图可能不连通或已完成)" << endl;
        }

        cout << "\n--- 步骤 " << i << ".a: 查找 V-U 中 lowcost 最小的顶点 (min_cost 初始为 INF) ---" << endl;
        for (int j = 0; j < V; ++j)
        {
            // lowcost[j] > 0 表示 j 属于 V-U
            if (lowcost[j] > 0)
            {
                string j_name = g.vertex_names[j];
                string current_min_cost_str = (min_cost > INF) ? string("INF") : to_string(min_cost);
                string lowcost_j_str = (lowcost[j] >= INF) ? string("INF") : to_string(lowcost[j]);

                if (lowcost[j] < min_cost)
                {
                    min_cost = lowcost[j];
                    k = j;
                }
            }
        }
        cout << "--- 查找完成：选取顶点 " << (k == -1 ? "无" : g.vertex_names[k]) << "，最小权重: " << (k == -1 ? "N/A" : to_string(min_cost)) << " ---" << endl;

        if (k == -1)
        {
            cout << "警告: 图不连通或发生错误!" << endl;
            break;
        }

        // b) 将顶点 k 加入 U
        cout << "\n--- 步骤 " << i << ".b: 选取顶点 " << g.vertex_names[k]
             << " (来自 " << g.vertex_names[closest[k]] << ")，权重: " << min_cost << " ---" << endl;

        mst_weight += min_cost;
        edge_count++;

        // 标记 k 已加入 U
        lowcost[k] = 0;

        // c) 更新 lowcost 和 closest 数组
        // k 是新加入 U 的顶点
        string k_name = g.vertex_names[k];
        cout << "--- 步骤 " << i << ".c: 更新 lowcost 和 closest (新加入顶点 " << k_name << ") ---" << endl;

        for (int j = 0; j < V; ++j)
        {
            // j 属于 V-U
            if (lowcost[j] > 0)
            {
                string j_name = g.vertex_names[j];
                int new_cost = g.edges[k][j];
                int current_lowcost = lowcost[j];
                string closest_j_name = g.vertex_names[closest[j]]; // 获取旧边连接的U中顶点

                cout << "  * 检查顶点 V-U 中的 " << j_name << "：";

                // 检查 k 到 j 的新边是否更小
                if (new_cost < current_lowcost)
                {
                    string current_lowcost_str = (current_lowcost == INF ? string("INF") : to_string(current_lowcost));

                    if (new_cost < INF)
                    {
                        cout << "新边 (" << k_name << "," << j_name << ") 权值 " << new_cost
                             << " < 旧边 (" << closest_j_name << "," << j_name << ") 权值 " << current_lowcost_str
                             << "，**更新** lowcost[" << j_name << "]=" << new_cost << "，closest[" << j_name << "]=" << k_name << "。" << endl;
                        lowcost[j] = new_cost;
                        closest[j] = k;
                    }
                    else
                    {
                        // 理论上 new_cost (INF) < current_lowcost (非INF) 不会发生
                        cout << "新边无连接 (INF)，旧边权值 " << current_lowcost_str << " 不变。" << endl;
                    }
                }
                else
                {
                    string new_cost_str = (new_cost == INF ? string("INF") : to_string(new_cost));
                    string current_lowcost_str = (current_lowcost == INF ? string("INF") : to_string(current_lowcost));

                    if (current_lowcost == INF)
                    {
                        cout << "新边 (" << k_name << "," << j_name << ") 权值 " << new_cost_str
                             << "。顶点 " << j_name << " 仍不可达 (lowcost=INF)。" << endl;
                    }
                    else
                    {
                        cout << "新边 (" << k_name << "," << j_name << ") 权值 " << new_cost_str
                             << " >= 旧边 (" << closest_j_name << "," << j_name << ") 权值 " << current_lowcost_str
                             << "，**不更新**。" << endl;
                    }
                }
            }
        }
        cout << "---------------------------------------------------------" << endl;
    }

    cout << "\n-----------------------------------" << endl;
    cout << "最小生成树的总权重: " << mst_weight << endl;
    cout << "===================================" << endl;
}

int main()
{
    // 设置控制台输出 UTF-8 编码
    SetConsoleOutputCP(65001);

    // 设置输出格式
    cout << "INF (无穷大) = " << INF << endl;

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

    // 暂停，等待用户按键
    cout << "\n程序执行完毕。";
    system("pause");

    return 0;
}