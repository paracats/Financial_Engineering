' VBA For Quantitative Finance                                
' Monte Carlo Methods
' Author: David Li                                           

Function SuccessfulRuns(Initial, _
Drawdown, Interest, Mean, Sigma, _
PercentRisky, Years, Runs)
    Dim PortfolioValue() As Double
    ReDim PortfolioValue(Years + 1)
    Dim Success As Integer
    
    Up = Exp(Mean + Sigma)
    Down = Exp(Mean - Sigma)
    
    PiUp = (Exp(Interest) - Down) / (Up - Down)
    PiDown = 1 - PiUp

    For Index = 1 To Runs
    For j = 1 To Years
    Randomize
    
    PortfolioValue(0) = Initial
    If Rnd > PiDown Then
       PortfolioValue(j) = _
       PortfolioValue(j - 1) * _
       PercentRisky * Up + PortfolioValue(j - 1) _
       * (1 - PercentRisky) * _
       Exp(Interest) - Drawdown
       
    Else
      PortfolioValue(j) = PortfolioValue(j - 1) * _
      PercentRisky * Down + PortfolioValue(j - 1) _
      * (1 - PercentRisky) * Exp(Interest) _
      - Drawdown
    End If

    Next j
       If PortfolioValue(Years) > 0 _
       Then Success = Success + 1
    Next Index
    
    SuccessfulRuns = Success / Runs
    
End Function
