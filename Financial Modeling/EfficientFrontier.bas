
 Sub Solve()       
        SolverOk SetCell: = ”$B$19”, MaxMinVal: = 1, 
        ValueOf: = ”0”, ByChange: = ”$B$11:$B$14”       
        SolverSolve UserFinish: = True   
