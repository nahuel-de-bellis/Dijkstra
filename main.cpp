#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF (1 << 29)

using namespace std;

struct Pares
{
    int nodo;
    int costo;
    Pares (int _costo, int _nodo)
    {

        costo = _costo;
        nodo = _nodo;

    }
};

struct Aristas
{
    int nodo;
    int costo;
    Aristas (int _nodo, int _costo)
    {

        nodo = _nodo;
        costo = _costo;

    }
};

bool operator<(const Pares &a, const  Pares &b)
{
    return a.costo > b.costo;
}

struct grafo
{
    vector <vector <Aristas> > adj;
    vector <int> dist;
    vector <int> padres;
    vector <int> camino;
    int nodos, aristas;

    void leer()
    {
        cin >> nodos >> aristas;

        adj.resize(nodos+1);
        int desde, hasta, costo;
        for(int i = 0; i<nodos;i++)
        {
            cin >> desde >> hasta >> costo;
            adj[desde].push_back(Aristas(hasta, costo));
            adj[hasta].push_back(Aristas(desde, costo));
        }

    }

    void dijkstra(int inicio)
    {
        dist = vector <int> (nodos+1, INF);
        padres = vector <int> (nodos+1, -1);
        dist[inicio] = 0;

        queue <Pares> cola;
        cola.push(Pares(0, inicio));
        while(cola.size())
        {
            Pares p = cola.front();
            cola.pop();
            int nodo = p.nodo;
            int vecino = 0;
            int costo =0;
            for(auto i:adj[nodo])
            {
                vecino = i.nodo;
                costo = i.costo;
                if(dist[nodo] + costo < dist[vecino])
                {
                    dist[vecino] = dist[nodo] + costo;
                    padres[vecino] = nodo;
                    cola.push(Pares(dist[vecino], vecino));
                }
            }
        }

    }

    vector <int> recorrido(int fin)
    {
        int c = fin;
        do
        {
            camino.push_back(c);
            c = padres[c];

        }
        while(c != -1);

        reverse(camino.begin(), camino.end());

        return camino;
    }

};



int main()
{
    grafo g;
    g.leer();
    g.dijkstra(1);
    vector <int> camino = g.recorrido(g.nodos);
    cout << "el recorrido mas corto es: ";
    for(auto i:camino)
    {
        cout << i<< " ";

    }


    return 0;
}#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF (1 << 29)

using namespace std;

struct Pares
{
    int nodo;
    int costo;
    Pares (int _costo, int _nodo)
    {

        costo = _costo;
        nodo = _nodo;

    }
};

struct Aristas
{
    int nodo;
    int costo;
    Aristas (int _nodo, int _costo)
    {

        nodo = _nodo;
        costo = _costo;

    }
};

bool operator<(const Pares &a, const  Pares &b)
{
    return a.costo > b.costo;
}

struct grafo
{
    vector <vector <Aristas> > adj;
    vector <int> dist;
    vector <int> padres;
    vector <int> camino;
    int nodos, aristas;

    void leer()
    {
        cin >> nodos >> aristas;

        adj.resize(nodos+1);
        int desde, hasta, costo;
        for(int i = 0; i<nodos;i++)
        {
            cin >> desde >> hasta >> costo;
            adj[desde].push_back(Aristas(hasta, costo));
            adj[hasta].push_back(Aristas(desde, costo));
        }

    }

    void dijkstra(int inicio)
    {
        dist = vector <int> (nodos+1, INF);
        padres = vector <int> (nodos+1, -1);
        dist[inicio] = 0;

        queue <Pares> cola;
        cola.push(Pares(0, inicio));
        while(cola.size())
        {
            Pares p = cola.front();
            cola.pop();
            int nodo = p.nodo;
            int vecino = 0;
            int costo =0;
            for(auto i:adj[nodo])
            {
                vecino = i.nodo;
                costo = i.costo;
                if(dist[nodo] + costo < dist[vecino])
                {
                    dist[vecino] = dist[nodo] + costo;
                    padres[vecino] = nodo;
                    cola.push(Pares(dist[vecino], vecino));
                }
            }
        }

    }

    vector <int> recorrido(int fin)
    {
        int c = fin;
        do
        {
            camino.push_back(c);
            c = padres[c];

        }
        while(c != -1);

        reverse(camino.begin(), camino.end());

        return camino;
    }

};



int main()
{
    grafo g;
    g.leer();
    g.dijkstra(1);
    vector <int> camino = g.recorrido(g.nodos);
    cout << "el recorrido mas corto es: ";
    for(auto i:camino)
    {
        cout << i<< " ";

    }


    return 0;
}
