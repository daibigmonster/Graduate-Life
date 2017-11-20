//层次遍历：因为按层打印的顺序决定应该先打印根结点，所以我们从树的根结点开始分析。为了接下来能够打印值为8的结点的两个子结点，我们应该在遍历到该结点时把值为6和10的来拿各个结点保存到一个容器里，现在容器内就有两个结点了。按照从左到右打印的要求，我们先取出值为6的结点。打印出值6之后把它的值分别为5和7的两个结点放入数据容器。此时数据容器中有三个结点，值分别为10,5,7。接下来我们从数据容器中取出值为10的结点。注意到值为10的结点比值为5、7的结点先放入容器，此时又比这两个结点先取出，这就是我们通常说的先入先出，因此不难看出，这个数据容器应该是一个队列。
//通过上面具体例子的分析，我们可以找到从上到下打印二叉树的规律：每一次打印一个结点的时候，如果该结点由子结点，则把该子结点放到一个队列的末尾，接下来到队列的头部取出最早进入队列的结点，重复前面的打印操作，直至队列中所有的结点都被打印出来为止。
 void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot)
 {
     if(!pTreeRoot)return;
     std::deque<BinaryTreeNode *>dequeTreeNode;
     dequeTreeNode.push_back(pTreeRoot);
     while(dequeTreeNode.size())
     {
         BinaryTreeNode *pNode=dequeTreeNode.front();
         dequeTreeNode.pop_front();
         printf("%d",pNode->m_nValue);
         if(pNode->m_pLeft)
             dequeTreeNode.push_back(pNode->m_pLeft);
         if(pNode->m_pRight->m_nValue)
             dequeTreeNode.push_back(pNode->m_pLeft);
      }
 }
