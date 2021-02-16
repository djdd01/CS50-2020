Ball = class{}

function Ball:init(x, y, radius, segments)
    self.x = x
    self.y = y 
    self.radius = radius
    self.segments = segments
    self.dx = math.random(2) == 1 and -400 or 400
    self.dy = math.random(-200, 200)
end

function Ball:collides(box)
    if self.x - self.radius / 2 > box.x + box.width or self.x + self.radius / 2 < box.x then
        return false
    end    
    if self.y - self.radius / 2 > box.y + box.height or self.y + self.radius / 2 < box.y then
        return false
    end
    
    return true
end

function Ball:reset()
    self.x = VIRTUAL_WIDTH / 2 - 4
    self.y = VIRTUAL_HEIGHT / 2 - 4
    self.dx = math.random(2) == 1 and -400 or 400
    self.dy = math.random(-400, 400)
end

function Ball:update(dt)
    self.x = self.x + self.dx * dt
    self.y = self.y + self.dy * dt
end

function Ball:render()
    love.graphics.circle('fill', self.x, self.y, self.radius, self.segments)
end    