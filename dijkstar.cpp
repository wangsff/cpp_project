
#define MAXVEX 9
#define INFINITY 65535

typedef int Patharc[MAXVEX];
typedef int ShortPathTable[MAXVEX];

void Dijkstar(MGraph G, int V0, Patharc p, ShortPathTable D)
{
    int v, w, k, min;
    int final[MAXVEX];
    for (v = 0; v < MAXVEX; ++v)
    {
        final[v] = 0;
        D[v] = G[v0][v];
        p[v] = 0;
    }
    D[v0] = 0;
    final[v0] = 1;

    for (v = 1; v < MAXVEX; ++v)
    {
        min = INFINITY;
        for (w = 0; w < MAXVEX; ++w)
        {
            if (!final[w] && D[w] < min)
            {
                k = w;
                min = D[w];
            }
        }
        final[k] = 1;
        for (w = 0; w < MAXVEX; ++w)
        {
            if (!final[w] && min + G[k][w] < D[w])
            {
                D[w] = min + G[k][w];
                p[w] = k;
            }
        }
    }
}