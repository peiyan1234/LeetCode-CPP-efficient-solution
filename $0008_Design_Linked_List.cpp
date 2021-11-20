/*
Runtime: 32 ms, faster than 95.54% of C++ online submissions for Design Linked List.
Memory Usage: 19.5 MB, less than 84.03% of C++ online submissions for Design Linked List.
*/

class MyLinkedList {
public:
    MyLinkedList()
    : m_size( 0 ),
      head_node( nullptr ),
      end_node( nullptr )
    {

    }
        
    int get(const int& index)
    {
        if ( -1 < index && index < m_size )
        {
            Node* node = head_node;
            int i = 0;
            while ( 1 )
            {
                if ( i == index )
                {
                    return node->val;
                }
                else
                {
                    node = node->next;
                    i++;
                }
            }
        }
        return -1;
    }
        
    void addAtHead(const int& val)
    {
        if ( 0 == m_size )
        {
            Node* node = new Node( val );
            head_node = node;
            end_node = node;
        }
        else
        {
            Node* node = new Node( val, head_node );
            head_node = node;
        }
        m_size++;
    }
        
    void addAtTail(const int& val)
    {
        if ( 0 == m_size )
        {
            addAtHead( val );
        }
        else
        {
            end_node->next = new Node( val );
            end_node = end_node->next;
            m_size++;
        }        
    }
    
    void addAtIndex(const int& index, const int& val)
    {
        if ( -1 < index && index < m_size )
        {
            if ( 0 == index )
            {
                addAtHead( val );
                return;
            }
            
            Node* buf_node = head_node;
            int i = 0;
            while ( i < index )
            {
                if ( i == index-1 ) break;
                buf_node = buf_node->next;
                i++;
            }
            Node* node = new Node( val, buf_node->next );
            buf_node->next = node;
            m_size++;
        }
        else if ( index == m_size )
        {
            addAtTail( val );
        }
        else return;

    }
    
    void deleteAtIndex(const int& index)
    {
        if ( -1 < index && index < m_size )
        {
            if ( m_size == 1 )
            {
                m_size--;
                delete head_node;
                head_node = nullptr;
                return;
            }
            
            if ( 0 == index )
            {
                m_size--;
                Node* buf_node = head_node->next;
                head_node->next = nullptr;
                delete head_node;
                head_node = buf_node;
                return;
            }
            
            Node* buf_node = head_node;
            int i = 0;
            while ( i < index )
            {
                if ( i == index-1 ) break;
                buf_node = buf_node->next;
                i++;
            }
            
            Node* del_node = buf_node->next;

            if ( index != m_size-1 )
            {
                buf_node->next = del_node->next;
                del_node->next = nullptr;
            }
            else
            {
                end_node = buf_node;
            }
            delete del_node;
            del_node = nullptr;
            m_size--;
        }
        else return;
    }
    
private:
    int m_size;
    struct Node
    {
        int val;
        Node* next;
        Node(): val(0), next(nullptr) {};
        Node( int x ): val(x), next(nullptr) {};
        Node( int x, Node* next): val(x), next(next) {};
    };

    Node* head_node;
    Node* end_node;
    
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
