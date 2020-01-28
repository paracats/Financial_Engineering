
' VBA For Quantitative Finance                                
' AmericanPuts
' Author: David Li   

Function Binomial_amer_put(Up, Down, Interest, _
Stock, Exercise, Periods)
    q_up = (Interest - Down) / (Interest * _
    (Up - Down))
    q_down = 1 / Interest - q_up

    Dim OptionReturnEnd() As Double
    Dim OptionReturnMiddle() As Double
    ReDim OptionReturnEnd(Periods + 1)
    
    For State = 0 To Periods
    OptionReturnEnd(State) = Application.Max(Exercise _
    - Stock * Up ∧ State * Down ∧ (Periods - State), 0)
    Next State
    
    For Index = Periods - 1 To 0 Step -1
        ReDim OptionReturnMiddle(Index)
        For State = 0 To Index
          OptionReturnMiddle(State) = Application.Max _
          (Exercise - Stock * Up ∧ State * Down ∧ _
          (Index - State), _
          q_down * OptionReturnEnd(State) + q_up * _
          OptionReturnEnd(State + 1))
        Next State
        ReDim OptionReturnEnd(Index)
        For State = 0 To Index
            OptionReturnEnd(State) = _
            OptionReturnMiddle(State)
        Next State
    Next Index
    Binomial_amer_put = OptionReturnMiddle(0)
End Function
