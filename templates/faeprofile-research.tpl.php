<?php
/**
 * @file
 *
 * Available template variables are:
 *
 * $research - An array of all research.
 * $schemes  - An array of research grant schemes, each of which contains an
 *             array of grants.
 * $year     - An array of years, each of which contains an array of grants
 *             for that year.
 */
?>

<?php if(isset($year) && is_array($year)): ?>
	<?php foreach($year as $each_year_key => $each_year): ?>
		<h4><?php echo $each_year_key ?></h4>
		<ul>
			<?php foreach($each_year as $each_project): ?>
				<li><?php echo $each_project ?></li>
			<?php endforeach; ?>
		</ul>
	<?php endforeach; ?>	
<?php endif; ?>
