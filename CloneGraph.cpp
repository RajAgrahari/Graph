//https://practice.geeksforgeeks.org/problems/clone-graph/1
Node* cloneGraph(Node* node) 
    {
        Node* root = new Node(node->val);
        queue<Node*> q1, q2;
        q1.push(node);
        q2.push(root);
        while(!q1.empty())
        {
            Node* front1 = q1.front();
            Node* front2 = q2.front();
            q1.pop();
            q2.pop();
            front1->val = 0;
            for(Node* nbr : front1->neighbors)
                if(nbr->val)
                {
                    Node* temp = new Node(nbr->val);
                    temp->neighbors.push_back(front2);
                    front2->neighbors.push_back(temp);
                    q1.push(nbr);
                    q2.push(temp);
                }
        }
        return root;
    }
