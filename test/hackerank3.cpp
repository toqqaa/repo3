#include<iostream>
class students{
public:
int score[5];
int sum;
void input() {

for(int i=0; i<5; i++)
{
    std::cin>>score[i];
}

}
int calculateTotalScore() {


for(int i=0; i<5; i++)
{
   sum=sum+score[i];
}
return sum;
}


};
int main()
{
    int n;
    std::cin>>n;
    students *student = new students[n];
    for(int i=0; i<n; i++)
    {
        student[i].input();
    }
    int kristenScore= student[0].calculateTotalScore();

    int count = 0;
	for (int i = 1; i < n; i++)
	{
		int totalscore = student[i].calculateTotalScore();
		if (totalscore > kristenScore)
		
			count++;
		}
	

	
	std::cout << count;

	return 0;
}
















