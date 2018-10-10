
Function tintercept(yarray, xarray)        
    tintercept  =  Application.Index(Application. _        
    LinEst(yarray, xarray, , 1), 1, 2) / _        
    Application.Index(Application.LinEst(yarray, _        
    xarray, , 1), 2, 2)    
End Function  

Function tslope(yarray, xarray)        
    tslope  =  Application.Index(Application. _        
    LinEst(yarray, xarray, , 1), 1, 1) / _        
    Application.Index(Application.LinEst(yarray, _        
    xarray, , 1), 2, 1)    
End Function  
