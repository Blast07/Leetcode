//1106

bool parseBoolExpr(string expr) {
	stack <char> opr; //operator
	stack <char> opd; //operand

	for (int i=0;i<expr.size();i++){
		if ((expr[i] == '&') || (expr[i] == '!') || (expr[i] == '|')){
			opr.push(expr[i]);
		}else if(expr[i] == ',' || expr[i] == ')'){
			
			char res = opd.top(); opd.pop();
			while(opd.top()!= '('){
				char top = opd.top(); opd.pop();
				if (opr.top()=='&'){
					if (!(res == 't' && top == 't')){
						res = 'f';	
					}
				}else if(opr.top() == '|'){
					if (!(res=='f' && top == 'f')){
						res = 't';	
					}
				}
			}
			if (opr.top() == '!'){
				if (res == 't')
					res = 'f';
				else
					res = 't';
			}

			if (expr[i] == ')'){
				opd.pop();
				opr.pop();
			}
			opd.push(res);

		
		}else{
			opd.push(expr[i]);
		}
	}

	if (opd.top() == 'f')
		return false;
	else
		return true;

}
