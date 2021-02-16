select title from movies
join ratings on movies.id = ratings.movie_id
join stars on ratings.movie_id = stars.movie_id
join people on person_id = people.id
where people.name = "Chadwick Boseman"
order by rating desc
limit 5;