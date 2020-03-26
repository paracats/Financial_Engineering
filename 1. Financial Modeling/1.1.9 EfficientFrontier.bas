' VBA For Quantitative Finance                                
' Efficient Frontier
' Author: Shaofei Li   

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
        Range(“Results”).Cells(counter, 2) _ 
        ActiveSheet.Range(“portfolio_sigma”)       
        Range(“Results”).Cells(counter, 3) _ 
        ActiveSheet.Range(“portfolio_mean”)       
        Range(“Results”).Cells(counter, 4) _ 
        ActiveSheet.Range(“x_1”)       
        Range(“Results”).Cells(counter, 5) _ 
        ActiveSheet.Range(“x_2”)       
        Range(“Results”).Cells(counter, 6) _ 
        ActiveSheet.Range(“x_3”)       
        Range(“Results”).Cells(counter, 7) _ 
        ActiveSheet.Range(“x_4”) 
   Next counter    
End Sub           ActiveSheet.Range(“x_3”)  
        Range(“Results”).Cells(counter, 7)  =  _       
            ActiveSheet.Range(“x_4”)  
   Next counter    
End Sub 
