' VBA For Quantitative Finance                                
' Monte Carlo Methods
' Author: Shaofei Li    

Function MCBarrierIn(Initial, Exercise, Barrier, Up, _
Down, Interest, Periods, Runs)
    Dim PricePath() As Double
    ReDim PricePath(Periods + 1)

    ‘Risk-neutral probabilities
    piup = (Interest - Down) / (Up - Down)
    pidown = 1 - piup

    Temp = 0
    
    For Index = 1 To Runs
       ‘Generate path
       For i = 1 To Periods
          PricePath(0) = Initial
          pathprob = 1
          If Rnd > pidown Then
             PricePath(i) = PricePath(i - 1) * Up
   
             Else:
             PricePath(i) = PricePath(i - 1) * Down
          End If
        Next i
        
          If Application.Max(PricePath) > Barrier Then _
          Callpayoff = _
              Application.Max(PricePath(Periods) - _
              Exercise, 0) _
              Else Callpayoff = 0
           Temp = Temp + Callpayoff
           
    Next Index
    
    MCBarrierIn = (Temp / Interest ∧ Periods) / Runs
    
End Function

Function MCBarrierOut(Initial, Exercise, _
Barrier, Up, Down, Interest, Periods, Runs)
    Dim PricePath() As Double
    ReDim PricePath(Periods + 1)
    
    ‘Risk-neutral probabilities
    piup = (Interest - Down) / (Up - Down)
    pidown = 1 - piup

    Temp = 0

    For Index = 1 To Runs
        ‘Generate path
        For i = 1 To Periods
           PricePath(0) = Initial
           pathprob = 1
           If Rnd > pidown Then
           PricePath(i) = PricePath(i - 1) * Up
           
           Else:
           PricePath(i) = PricePath(i - 1) * Down
           End If
         Next i
         
         If Application.Max(PricePath) < Barrier _
         Then Callpayoff = Application.Max _
         (PricePath(Periods) - Exercise, 0) _
         Else: Callpayoff = 0
         Temp = Temp + Callpayoff
         
    Next Index
    
    MCBarrierOut = (Temp / Interest ∧ Periods) _
    / Runs
    
End Function
