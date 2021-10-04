/* 
generate binary numbers
from 0 to n 
*/

vector<string> generate(int N)
{
	queue<string> q;
	vector<string> output;
	
	q.push("1");
	
	while (N--) {
	    output.push_back(q.front());
	    q.push(q.front() + "0");
	    q.push(q.front() + "1");
	    
	    q.pop();
	}
	
	return output;
}