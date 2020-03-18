' VBA For Quantitative Finance                                
' Price Path Simulation
' Author: S Li  

Sub PricePathSimulation()
Range(“starttime”) = Time

N = Range(“runs”).Value
mean = Range(“mean”)
sigma = Range(“sigma”)
delta_t = 1 / (2 * N)

ReDim price(0 To 2 * N) As Double

price(0) = Range(“initial_price”)

For Index = 1 To N
start:
    Static rand1, rand2, S1, S2, X1, X2
    rand1 = 2 * Rnd - 1
    rand2 = 2 * Rnd - 1
    S1 = rand1 ∧ 2 + rand2 ∧ 2
    If S1 > 1 Then GoTo start
    S2 = Sqr(-2 * Log(S1) / S1)
    X1 = rand1 * S2
    X2 = rand2 * S2
    
    price(2 * Index - 1) = price(2 * Index - 2)
    * Exp(mean * delta_t + _
        sigma * Sqr(delta_t) * X1)
    price(2 * Index) = price(2 * Index - 1) *
    Exp(mean * delta_t + _
        sigma * Sqr(delta_t) * X2)
Next Index

For Index = 0 To 2 * N
    Range(“output”).Cells(Index + 1, 1) = Index
    Range(“output”).Cells(Index + 1, 2) =
    price(Index)
Next Index

Range(“stoptime”) = Time
Range(“elapsed”) = Range(“stoptime”) -
Range(“starttime”)
Range(“elapsed”).NumberFormat = “hh:mm:ss”

End Sub
