bool VerifySquenceOfBST(int sequence[],int length)
{
    if(sequence==NULL||length)return false;
    int root=sequence[length-1];
    int i=0;
    //在二叉搜索树中左子树的结点小于根结点
    for(;i<length-1;++i)
    {
        if(sequence[i]>root)
            break;
    }
    int j=i;
    for(;j<length-1;++i)
    {
        if(sequence[j]<root)return false;
    }
    bool left=true;
    if(i>0)
        left=VerifySequenceOfBST(sequence,i);
    bool right=true;
    if(i<length-1)
        right=VerifySqequenceOfBST(sequence+i,length-i-1);
    return(lefr&&right);
}
