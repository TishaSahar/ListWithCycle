#include "List.h"

using namespace std;


int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    List L; L.addN(n1); L.addN(n2); L.addN(n3); L.addN(n1);
    L.Print();

    return 0;
}