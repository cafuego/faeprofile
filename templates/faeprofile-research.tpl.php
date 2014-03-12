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
	<h3>Grant information</h3>
	<?php foreach($year as $each_year_key => $each_year): ?>
		<?php 
			if(empty($each_year_key)) {
				$each_year_key_label = 'Other';
			}
			else {
				$each_year_key_label = $each_year_key;
			} 
		?>
		<h4><?php echo $each_year_key_label ?></h4>
		<ul>
			<?php foreach($each_year as $each_project): ?>
				<li class="faeprofile-block-research-list-item"><?php echo $each_project ?></li>
			<?php endforeach; ?>
		</ul>
	<?php endforeach; ?>

	<?php if(!empty($extra_grant_text)): ?>
		<h3>Additional grant information</h3>
		<?php echo $extra_grant_text ?>
	<?php endif; ?>	
<?php endif; ?>
