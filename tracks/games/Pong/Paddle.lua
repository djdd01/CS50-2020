Paddle = class{}

function Paddle:init(x, y, width, height)
    self.x = x
    self.y = y 
    self.width = width
    self.height = height
    self.dy = 0
end

function Paddle:update(dt)
    if self.dy < 0 then
        self.y = math.max(110, self.y + self.dy * dt)
    elseif self.dy > 0 then
        self.y = math.min(905, self.y + self.dy * dt)
    end
end         

function Paddle:render()
    love.graphics.rectangle('line', self.x, self.y, self.width, self.height)
end    