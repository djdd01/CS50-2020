select avg(rating) from ratings
join movies on movie_id = id
where year = 2012;