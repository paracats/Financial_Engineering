
 Function Binomial_eur_call(Up, Down, Interest, _    
 Stock, Exercise, Periods) 
   q_up  =  (Interest - Down) / _       
   (Interest * (Up - Down))       
   q_down  =  1 / Interest - q_up       
   Binomial_eur_call  =  0       
 For Index  =  0 To Periods 
   Binomial_eur_call  =  Binomial_eur_call _    
   +  Application.Combin(Periods, Index) _       
   * q_up  ∧  Index * q_down  ∧  (Periods - Index) _       
   * Application.Max(Stock * Up  ∧  Index * Down _       
   ∧  (Periods - Index) - Exercise, 0)       
 Next Index    
End Function   



 Function Binomial_eur_put(Up, Down, Interest, _    
 Stock, Exercise, Periods)   
   Binomial_eur_put  =  Binomial_eur_call _       
   (Up, Down, Interest, Stock, Exercise, _       
   Periods)  +  Exercise / Interest  ∧  Periods - Stock    
 End Function  
