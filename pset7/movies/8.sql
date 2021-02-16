select name from
people join stars on people.id = person_id
join movies on movie_id = movies.id
where title = "Toy Story";