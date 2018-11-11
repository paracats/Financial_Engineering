
 Sub Solve()       
        SolverOk SetCell: = ”$B$19”, MaxMinVal: = 1, 
        ValueOf: = ”0”, ByChange: = ”$B$11:$B$14”       
        SolverSolve UserFinish: = True   
End Sub    
Sub Doit() 
    Range(“Results”).ClearContents      
    For counter  =  1 To 40       
        Range(“constant”)  =  -0.04  +  counter * 0.005       
        Solve       
        Application.SendKeys (“{Enter}”)       
        Range(“Results”).Cells(counter, 1) _ 
        ActiveSheet.Range(“constant”)   
