__kernel void d2o(__global*A,__global* C)
{
int i=get_global_id(0);
int remain=9,q,answer=0,p=1;
int num=A[i];
  while(q!=0)
  {
  q=num/8;
  remain=num%8;
  answer=p*remain+answer;
  num=q;
  p*=10;
  
  }
  C[i]=answer;
  }