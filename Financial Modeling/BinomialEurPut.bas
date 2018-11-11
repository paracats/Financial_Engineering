
 Function Binomial_eur_call(Up, Down, Interest, _    
 Stock, Exercise, Periods) 
   
   
   
   q_up  =  (Interest - Down) / _       
   (Interest * (Up - Down))       
   q_down  =  1 / Interest - q_up       
   Binomial_eur_call  =  0       
   For Index  =  0 To Periods 
