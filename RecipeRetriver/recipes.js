module.exports.init = function(app,pool){


  app.get('/all-recipes', function (request, response) {
    if(request.query.id){ // Give back the recipe with that ID including ingredients
      const getIngredientsQuery = `SELECT size,ingredientid
                                   FROM ingredientsrecipes WHERE recipeid = $1`
      const getIngredientsData = [request.query.id]

      pool
        .query(getIngredientsQuery, getIngredientsData)
        .then(results => {
          response.json({info: results.rows})
        })
        .catch(e => console.error(e.stack))

     }else{ // Return all recipes with ids
      const getAllRecipesQuery = `SELECT ingredientsrecipes.recipeid as recipeid, recipes.name as recipename, ingredients.name as ingname, ingredientsrecipes.size FROM ingredientsrecipes
                                  INNER JOIN recipes on  ingredientsrecipes.recipeid = recipes.id
                                  INNER JOIN ingredients on ingredientsrecipes.ingredientid = ingredients.id`
      pool
        .query(getAllRecipesQuery)
        .then(results => {
          response.json(results.rows)
        })
        .catch(e => console.error(e.stack))
     }

  })

}
