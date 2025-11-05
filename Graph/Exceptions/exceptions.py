class VertexError(Exception):
    def __init__(self, message: str):
        super.__init__(message)
        self.message: str = message
        
        
class EdgeError(Exception):
    def __init__(self, message: str):
        super.__init__(self)
        self.message: str = message