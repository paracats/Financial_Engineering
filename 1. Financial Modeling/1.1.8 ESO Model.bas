' VBA For Quantitative Finance                                
' ESO Model
' Author: Shaofei Li   

Function ESO(Stock As Double, X As Double, T As _
Double, Vest As Double, Interest As Double, _
Sigma As Double, Divrate As Double, _
Exitrate As Double, Multiple As Double, _
n As Single)

    Dim Up As Double, Down As Double, _
    R As Double, Div As Double, _
    piUp As Double, piDown As Double, _
    Delta As Double, i As Integer, j As Integer
    
  ReDim Opt(T * n, T * n)
  ReDim S(T * n, T * n)
  Up = Exp(Sigma * Sqr(1 / n))
  Down = Exp(-Sigma * Sqr(1 / n))
  R = Exp(Interest / n)
  Div = Exp(-Divrate / n)
  ‘Risk-neutral Up and Down probabilities
  piUp = (R * Div - Down) / (Up - Down)
  piDown = (Up - R * Div) / (Up - Down)
  
  ’ Defining the stock price
  ‘j is the number of Up steps
   For i = 0 To T * n
      For j = 0 To i
      S(i, j) = Stock * Up ∧ j _
      * Down ∧ (i - j)
      Next j
  Next i
  ‘Option value on the last nodes of tree
  For i = 0 To T * n
      Opt(T * n, i) = _
      Application.Max(S(T * n, i) - X, 0)
  Next i

  ‘Early exercise when stock price > multiple
  ‘ * exercise after vesting
  For i = T * n - 1 To 0 Step -1
  For j = 0 To i
  If i > Vest * n And S(i, j) >= Multiple * X _
  Then Opt(i, j) = Application.Max(S(i, j) - X, 0)
  If i > Vest * n And S(i, j) < Multiple * X _
  Then Opt(i, j) = ((1 - Exitrate / n) * _
  (piUp * Opt(i + 1, j + 1) + piDown * _
  Opt(i + 1, j)) / R + Exitrate / n * _
  Application.Max(S(i, j) - X, 0))
  If i <= Vest * n Then Opt(i, j) = _
  (1 - Exitrate / n) * (piUp * _
  Opt(i + 1, j + 1) + piDown * Opt(i + 1, j)) / R
  
  Next j
  Next i

  ESO = Opt(0, 0)
End Function
